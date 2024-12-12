#pragma once

#include "../camera/camera.hpp"
#include "../game_object/game_object.hpp"

#include <vulkan/vulkan.h>

namespace BlockyVulkan {

    struct FrameInfo {
        int frameIdx;
        float deltaTime;
        VkCommandBuffer commandBuffer;
        Camera &cam;
        VkDescriptorSet globalDescriptorSet;
        GameObject::Map &gameObjects;
    };
}