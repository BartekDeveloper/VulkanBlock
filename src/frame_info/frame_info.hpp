#pragma once

#include "../camera/camera.hpp"
#include "../game_object/game_object.hpp"

#include <vulkan/vulkan.h>

namespace BlockyVulkan {

    using glm::vec2;
    using glm::vec3;
    using glm::vec4;
    using glm::mat2;
    using glm::mat3;
    using glm::mat4;

    #define MAX_LIGHTS 32

    struct PointLight_t {
        vec4 position{}; // ignore w
        vec4 color{}; // w is power
    };

    // Some ubo for lighting i guess...
    struct GlobalUBO {
        mat4 projection{ 1.f };
        mat4 view{ 1.f };
        /*    vec3 lightDirection = glm::normalize(vec3{1.f, -3.f, -1.f});*/
        vec4 ambientLight{ 1.f, 1.f, 1.f, .03f };
        PointLight_t pointLights[MAX_LIGHTS];
        int numLights;
    };

    struct FrameInfo {
        int frameIdx;
        float deltaTime;
        VkCommandBuffer commandBuffer;
        Camera &cam;
        VkDescriptorSet globalDescriptorSet;
        GameObject::Map &gameObjects;
    };
}