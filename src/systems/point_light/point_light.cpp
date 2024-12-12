#include "point_light.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <stdexcept>

namespace BlockyVulkan {
    PointLight::PointLight(Device &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout) : device{device} {
        CreatePipelineLayout(globalSetLayout);
        CreatePipeline(renderPass);
    }

    PointLight::~PointLight() { vkDestroyPipelineLayout( device.device(), pipelineLayout, nullptr ); }

    void PointLight::CreatePipelineLayout(VkDescriptorSetLayout globalSetLayout) {
        //// Creating push constants
        //VkPushConstantRange pushConstRange{};
        //pushConstRange.stageFlags =
        //    VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
        //pushConstRange.offset = 0;
        //pushConstRange.size = sizeof( SimplePushConstantData );

        // Layout for descriptor sets
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts{globalSetLayout};

        // Setting up Layout Create Info
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};

        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = static_cast<uint32_t>(descriptorSetLayouts.size());
        pipelineLayoutInfo.pSetLayouts = descriptorSetLayouts.data();
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;

        if( vkCreatePipelineLayout( device.device(), &pipelineLayoutInfo, nullptr,
            &pipelineLayout ) != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to create pipeline layout!" );
        }
    }

    void PointLight::CreatePipeline(VkRenderPass renderPass) {
        assert( pipelineLayout != nullptr &&
            "Cannot create pipeline before pipeline layout!" );

        PipelineConfigInfo pipelineConfig{};
        Pipeline::DefaultPipelineConfigInfo( pipelineConfig );

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

    void PointLight::Render(FrameInfo &frameInfo) {
        pipeline->Bind( frameInfo.commandBuffer );

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

        vkCmdDraw(frameInfo.commandBuffer, 6, 1, 0, 0);
    }
}