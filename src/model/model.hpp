#pragma once

#include "../device/device.hpp"
#include <vulkan/vulkan.h>

#define GLM_FORCE_RADIANS // forcing radians instead of degrees (no matter your os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <vector>

namespace BlockyVulkan {

class Model {

  public:

    struct Vertex {
        glm::vec2 position;
        glm::vec3 color;

        static std::vector<VkVertexInputBindingDescription> GetBindingDescriptions();
        static std::vector<VkVertexInputAttributeDescription> GetAttributeDescriptions();

    };

    Model(Device &device, const std::vector<Vertex> &verticies );
    ~Model();

    Model( const Model & ) = delete;
    Model &operator = ( const Model & ) = delete;

    void Bind( VkCommandBuffer commandBuffer );
    void Draw( VkCommandBuffer commandBuffer );

  private:
    void CreateVertexBuffers(const std::vector<Vertex> &verticies);

    Device &device;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    uint32_t vertexCount;
};
}
