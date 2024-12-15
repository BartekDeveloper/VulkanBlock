#include "point_light.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <stdexcept>
#include <cassert>

namespace BlockyVulkan {

    struct PointLightPushConst {
        vec4 position{};
        vec4 color{};
        float radius;
    };

    PointLight::PointLight(Device &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout) : device{ device } {
        CreatePipelineLayout(globalSetLayout);
        CreatePipeline(renderPass);
    }

    PointLight::~PointLight() { vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr); }

    void PointLight::CreatePipelineLayout(VkDescriptorSetLayout globalSetLayout) {
        // Creating push constants
        VkPushConstantRange pushConstRange{};
        pushConstRange.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
        pushConstRange.offset = 0;
        pushConstRange.size = sizeof(PointLightPushConst);

        // Layout for descriptor sets
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts{ globalSetLayout };

        // Setting up Layout Create Info
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};

        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = static_cast<uint32_t>(descriptorSetLayouts.size());
        pipelineLayoutInfo.pSetLayouts = descriptorSetLayouts.data();
        pipelineLayoutInfo.pushConstantRangeCount = 1;
        pipelineLayoutInfo.pPushConstantRanges = &pushConstRange;

        if (vkCreatePipelineLayout(device.device(), &pipelineLayoutInfo, nullptr,
            &pipelineLayout) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create pipeline layout!");
        }
    }

    void PointLight::CreatePipeline(VkRenderPass renderPass) {
        assert(pipelineLayout != nullptr &&
            "Cannot create pipeline before pipeline layout!");

        PipelineConfigInfo pipelineConfig{};
        Pipeline::DefaultPipelineConfigInfo(pipelineConfig);

        pipelineConfig.attributeDescriptions.clear(); // So not to trigger validation layers' warnings
        pipelineConfig.bindingDescriptions.clear();   // So not to trigger validation layers' warnings

        pipelineConfig.renderPass = renderPass;
        pipelineConfig.pipelineLayout = pipelineLayout;

        pipeline = std::make_unique<Pipeline>(
            device,
            "assets/shaders/point_light.vert.spv",
            "assets/shaders/point_light.frag.spv",
            pipelineConfig
        );
    }

    void PointLight::Update(FrameInfo &frameInfo, GlobalUBO &ubo) {
        int lightIdx = 0;

        for (auto &kv : frameInfo.gameObjects) {
            auto &obj = kv.second;

            assert((lightIdx < MAX_LIGHTS) && "Max light count exceeded!");

            if (obj.pointLight == nullptr) continue;

            // Copy light to ubo
            ubo.pointLights[lightIdx].position = vec4(obj.transform3D.translation, 1.f);
            ubo.pointLights[lightIdx].color = vec4(obj.color, obj.pointLight->power);

            lightIdx++;
        }

        ubo.numLights = lightIdx;
    }

    void PointLight::Render(FrameInfo &frameInfo) {
        pipeline->Bind(frameInfo.commandBuffer);

        vkCmdBindDescriptorSets(
            frameInfo.commandBuffer,
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            pipelineLayout,
            0,
            1,
            &frameInfo.globalDescriptorSet,
            0,
            nullptr
        );

        for (auto &kv : frameInfo.gameObjects) {
            auto &obj = kv.second;

            if (obj.pointLight == nullptr) continue;

            PointLightPushConst push{};
            push.position = vec4(obj.transform3D.translation, 1.f);
            push.color = vec4(obj.color, obj.pointLight->power);
            push.radius = obj.transform3D.scale.x;

            vkCmdPushConstants(
                frameInfo.commandBuffer,
                pipelineLayout,
                VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT,
                0,
                sizeof(PointLightPushConst),
                &push
            );

            vkCmdDraw(frameInfo.commandBuffer, 6, 1, 0, 0);
        }
    }
}