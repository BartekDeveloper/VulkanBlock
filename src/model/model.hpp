#pragma once

#include "../device/device.hpp"
#include <vulkan/vulkan.h>

#define GLM_FORCE_RADIANS // forcing radians instead of degrees (no matter your os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include <string>

namespace BlockyVulkan {

    using glm::vec3;
    using glm::vec2;

    class Model {

    public:

        struct Vertex {
            vec3 position{};
            vec3 color{};
            vec3 normal{};
            vec2 uv{};

            static std::vector<VkVertexInputBindingDescription> GetBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> GetAttributeDescriptions();

            bool operator==(const Vertex &other) const {
                return ((position == other.position) && (color == other.color) && (normal == other.normal) && (uv == other.uv));
            }
        };

        struct Builder {
            std::vector<Vertex> vertices{};
            std::vector<uint32_t> indices{};

            void LoadModel(const std::string &filepath);

            Builder() = default;
        };

        Model(Device &device, const Model::Builder &builder);
        ~Model();

        static std::unique_ptr<Model> CreateModelFromFile(Device &device, const std::string &filepath);

        Model(const Model &) = delete;
        Model &operator = (const Model &) = delete;

        void Bind(VkCommandBuffer commandBuffer);
        void Draw(VkCommandBuffer commandBuffer);

    private:
        void CreateVertexBuffers(const std::vector<Vertex> &vertices);
        void CreateIndexBuffers(const std::vector<uint32_t> &indices);

        Device &device;

        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        uint32_t vertexCount;

        bool hasIndexBuffer{ false };
        VkBuffer indexBuffer;
        VkDeviceMemory indexBufferMemory;
        uint32_t indexCount;
    };
}
