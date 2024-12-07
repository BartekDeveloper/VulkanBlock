#include "model.hpp"

#include <cassert>
#include <cstring>

namespace BlockyVulkan {

Model::Model( Device &device, const std::vector<Vertex> &verticies ) : device(device) {
    CreateVertexBuffers( verticies );
}

Model::~Model() {
    vkDestroyBuffer( device.device(), vertexBuffer, nullptr );
    vkFreeMemory( device.device(), vertexBufferMemory, nullptr );
}

void Model::CreateVertexBuffers( const std::vector<Vertex> &verticies ) {
    vertexCount = static_cast<uint32_t>( verticies.size() );
    assert( vertexCount >= 3 && "Vertex count must be at least 3!" );

    VkDeviceSize bufferSize = sizeof( verticies[ 0 ] ) * vertexCount;

    device.createBuffer( bufferSize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                         vertexBuffer,
                         vertexBufferMemory
                       );

    void *data;
    vkMapMemory( device.device(), vertexBufferMemory, 0, bufferSize, 0, &data );
    memcpy( data, verticies.data(), static_cast<size_t>(bufferSize) );
    vkUnmapMemory( device.device(), vertexBufferMemory );
}

void Model::Draw( VkCommandBuffer commandBuffer ) {
    vkCmdDraw( commandBuffer, vertexCount, 1, 0, 0 );
}

void Model::Bind( VkCommandBuffer commandBuffer ) {
    VkBuffer buffers[] = { vertexBuffer };
    VkDeviceSize offsets[] = { 0 };
    vkCmdBindVertexBuffers( commandBuffer, 0, 1, buffers, offsets );
}

std::vector<VkVertexInputBindingDescription> Model::Vertex::GetBindingDescriptions() {
    std::vector<VkVertexInputBindingDescription> bindingDescriptions( 1 );
    bindingDescriptions[ 0 ].binding = 0;
    bindingDescriptions[ 0 ].stride = sizeof(Vertex);
    bindingDescriptions[ 0 ].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

    return bindingDescriptions;
}

std::vector<VkVertexInputAttributeDescription> Model::Vertex::GetAttributeDescriptions() {
    std::vector<VkVertexInputAttributeDescription> attributeDescriptions( 2 );

    // Position
    attributeDescriptions[ 0 ].binding = 0;
    attributeDescriptions[ 0 ].location = 0;
    attributeDescriptions[ 0 ].format = VK_FORMAT_R32G32B32_SFLOAT;
    attributeDescriptions[ 0 ].offset = offsetof(Vertex, position);

    // Color
    attributeDescriptions[ 1 ].binding = 0;
    attributeDescriptions[ 1 ].location = 1;
    attributeDescriptions[ 1 ].format = VK_FORMAT_R32G32B32_SFLOAT;
    attributeDescriptions[ 1 ].offset = offsetof(Vertex, color);

    /* Shortened form */
    /*
        @return {
            { 0, 0, VK_FORMAT_R32G32_SFLOAT, offsetof(Vertex, position)},
            { 0, 1, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, color)};
        }
    */

    return attributeDescriptions;
}

}
