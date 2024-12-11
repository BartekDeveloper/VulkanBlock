#include "model.hpp"

#include "../utils/utils.hpp"

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

#include <cassert>
#include <cstring>
#include <iostream>
#include <unordered_map>

namespace std {
    template<>
    struct hash<BlockyVulkan::Model::Vertex> {
        size_t operator()(BlockyVulkan::Model::Vertex const &vertex) const {
            size_t seed = 0;
            BlockyVulkan::HashCombine(seed, vertex.position, vertex.color, vertex.normal, vertex.uv);
            return seed;
        }
    };
}

namespace BlockyVulkan {

    Model::Model(Device &device, const Model::Builder &builder) : device(device) {
        CreateVertexBuffers(builder.vertices);
        CreateIndexBuffers(builder.indices);
    }

    Model::~Model() {
        vkDestroyBuffer(device.device(), vertexBuffer, nullptr);
        vkFreeMemory(device.device(), vertexBufferMemory, nullptr);

        if (hasIndexBuffer) {
            vkDestroyBuffer(device.device(), indexBuffer, nullptr);
            vkFreeMemory(device.device(), indexBufferMemory, nullptr);
        }
    }

    std::unique_ptr<Model> Model::CreateModelFromFile(Device &device, const std::string &filepath) {
        Builder builder{};
        builder.LoadModel(filepath);

        std::cout << "Vertex count: " << builder.vertices.size() << "\n";

        return std::make_unique<Model>(device, builder);
    }


    void Model::CreateVertexBuffers(const std::vector<Vertex> &vertices) {
        vertexCount = static_cast<uint32_t>(vertices.size());
        assert(vertexCount >= 3 && "Vertex count must be at least 3!");

        VkDeviceSize bufferSize = sizeof(vertices[0]) * vertexCount;

        VkBuffer stagingBuffer;
        VkDeviceMemory stagingBufferMemory;

        device.CreateBuffer(
            bufferSize,
            VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            stagingBuffer,
            stagingBufferMemory
        );

        void *data;
        vkMapMemory(device.device(), stagingBufferMemory, 0, bufferSize, 0, &data);
        memcpy(data, vertices.data(), static_cast<size_t>(bufferSize));
        vkUnmapMemory(device.device(), stagingBufferMemory);

        device.CreateBuffer(
            bufferSize,
            VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
            VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
            vertexBuffer,
            vertexBufferMemory
        );

        device.CopyBuffer(stagingBuffer, vertexBuffer, bufferSize);

        vkDestroyBuffer(device.device(), stagingBuffer, nullptr);
        vkFreeMemory(device.device(), stagingBufferMemory, nullptr);
    }

    void Model::CreateIndexBuffers(const std::vector<uint32_t> &indices) {
        indexCount = static_cast<uint32_t>(indices.size());
        hasIndexBuffer = (indexCount > 0);

        if (!hasIndexBuffer) {
            return;
        }

        VkDeviceSize bufferSize = sizeof(indices[0]) * indexCount;

        VkBuffer stagingBuffer;
        VkDeviceMemory stagingBufferMemory;

        device.CreateBuffer(
            bufferSize,
            VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            stagingBuffer,
            stagingBufferMemory
        );

        void *data;
        vkMapMemory(device.device(), stagingBufferMemory, 0, bufferSize, 0, &data);
        memcpy(data, indices.data(), static_cast<size_t>(bufferSize));
        vkUnmapMemory(device.device(), stagingBufferMemory);

        device.CreateBuffer(
            bufferSize,
            VK_BUFFER_USAGE_INDEX_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
            VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
            indexBuffer,
            indexBufferMemory
        );

        device.CopyBuffer(stagingBuffer, indexBuffer, bufferSize);

        vkDestroyBuffer(device.device(), stagingBuffer, nullptr);
        vkFreeMemory(device.device(), stagingBufferMemory, nullptr);
    }

    void Model::Draw(VkCommandBuffer commandBuffer) {
        if (hasIndexBuffer) {
            vkCmdDrawIndexed(commandBuffer, indexCount, 1, 0, 0, 0);
            return;
        }

        vkCmdDraw(commandBuffer, vertexCount, 1, 0, 0);
    }

    void Model::Bind(VkCommandBuffer commandBuffer) {
        VkBuffer buffers[] = { vertexBuffer };
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, buffers, offsets);

        if (hasIndexBuffer) {
            vkCmdBindIndexBuffer(commandBuffer, indexBuffer, 0, VK_INDEX_TYPE_UINT32);
        }
    }

    std::vector<VkVertexInputBindingDescription> Model::Vertex::GetBindingDescriptions() {
        std::vector<VkVertexInputBindingDescription> bindingDescriptions(1);
        bindingDescriptions[0].binding = 0;
        bindingDescriptions[0].stride = sizeof(Vertex);
        bindingDescriptions[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescriptions;
    }

    std::vector<VkVertexInputAttributeDescription> Model::Vertex::GetAttributeDescriptions() {
        std::vector<VkVertexInputAttributeDescription> attributeDescriptions{};

        // Positions
        attributeDescriptions.push_back({ 0, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, position) });
        // Colors
        attributeDescriptions.push_back({ 1, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, color)});
        // Normals
        attributeDescriptions.push_back({ 2, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, normal)});
        // UVs
        attributeDescriptions.push_back({ 3, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vertex, uv) });

        return attributeDescriptions;
    }


    void Model::Builder::LoadModel(const std::string &filepath) {
        tinyobj::attrib_t attrib;

        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;

        std::string warn, err;

        if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filepath.c_str())) {
            throw std::runtime_error("Failed to load object from .obj file:  " + filepath + "  \n\t  " + warn + err);
        }

        vertices.clear();
        indices.clear();
        std::unordered_map<Vertex, uint32_t> uniqueVertices;

        for (const auto &shape : shapes) {
            for (const auto &idx : shape.mesh.indices) {
                Vertex vertex{};

                if (idx.vertex_index >= 0) {
                    vertex.position = {
                        attrib.vertices[3 * idx.vertex_index + 0],
                        attrib.vertices[3 * idx.vertex_index + 1],
                        attrib.vertices[3 * idx.vertex_index + 2],
                    };

                    vertex.color = {
                        attrib.colors[3 * idx.vertex_index + 0],
                        attrib.colors[3 * idx.vertex_index + 1],
                        attrib.colors[3 * idx.vertex_index + 2],
                    };
                }

                if (idx.normal_index >= 0) {
                    vertex.normal = {
                        attrib.normals[3 * idx.normal_index + 0],
                        attrib.normals[3 * idx.normal_index + 1],
                        attrib.normals[3 * idx.normal_index + 2],
                    };
                }

                if (idx.texcoord_index >= 0) {
                    vertex.uv = {
                        attrib.texcoords[2 * idx.texcoord_index + 0],
                        attrib.texcoords[2 * idx.texcoord_index + 1],
                    };
                }

                if (uniqueVertices.count(vertex) == 0) {
                    uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
                    vertices.push_back(vertex);
                }
                indices.push_back(uniqueVertices[vertex]);
            }
        }
    }

}
