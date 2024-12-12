#pragma once

#include "../camera/camera.hpp"

#include <vulkan/vulkan.h>

namespace BlockyVulkan {

    struct FrameInfo {
        int frameIdx;
        float deltaTime;
        VkCommandBuffer commandBuffer;
        Camera &cam;
    };
}