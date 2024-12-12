#include "simple_render_system.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <stdexcept>

namespace BlockyVulkan {

    struct SimplePushConstantData {
        mat4 modelMatrix{ 1.f };  // Initializes main diagonal, not every entry
        mat4 normalMatrix{1.f};
    };

    SimpleRenderSystem::SimpleRenderSystem(Device &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout) : device{device} {
        CreatePipelineLayout(globalSetLayout);
        CreatePipeline(renderPass);
    }

    SimpleRenderSystem::~SimpleRenderSystem() { vkDestroyPipelineLayout( device.device(), pipelineLayout, nullptr ); }

    void SimpleRenderSystem::CreatePipelineLayout(VkDescriptorSetLayout globalSetLayout) {
        // Creating push constants
        VkPushConstantRange pushConstRange{};
        pushConstRange.stageFlags =
            VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
        pushConstRange.offset = 0;
        pushConstRange.size = sizeof( SimplePushConstantData );

        // Layout for descriptor sets
        std::vector<VkDescriptorSetLayout> descriptorSetLayouts{globalSetLayout};

        // Setting up Layout Create Info
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};

        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = static_cast<uint32_t>(descriptorSetLayouts.size());
        pipelineLayoutInfo.pSetLayouts = descriptorSetLayouts.data();
        pipelineLayoutInfo.pushConstantRangeCount = 1;
        pipelineLayoutInfo.pPushConstantRanges = &pushConstRange;

        if( vkCreatePipelineLayout( device.device(), &pipelineLayoutInfo, nullptr,
            &pipelineLayout ) != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to create pipeline layout!" );
        }
    }

    void SimpleRenderSystem::CreatePipeline(VkRenderPass renderPass) {
        assert( pipelineLayout != nullptr &&
            "Cannot create pipeline before pipeline layout!" );

        PipelineConfigInfo pipelineConfig{};
        Pipeline::DefaultPipelineConfigInfo( pipelineConfig );
        pipelineConfig.renderPass = renderPass;
        pipelineConfig.pipelineLayout = pipelineLayout;

        pipeline =
            std::make_unique<Pipeline>( device, "assets/shaders/simple.vert.spv",
                "assets/shaders/simple.frag.spv", pipelineConfig );
    }

    void SimpleRenderSystem::RenderGameObjects(FrameInfo &frameInfo) {
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

        for( auto &kv : frameInfo.gameObjects) {
            auto idx = kv.first;
            auto& obj = kv.second;

            if(obj.model == nullptr) continue;

            SimplePushConstantData push{};
            push.modelMatrix = obj.transform3D.Mat4();
            push.normalMatrix = obj.transform3D.NormalMatrix();

            vkCmdPushConstants(
                frameInfo.commandBuffer,
                pipelineLayout,
                VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT,
                0,
                sizeof(SimplePushConstantData),
                &push
            );

            obj.model->Bind( frameInfo.commandBuffer );
            obj.model->Draw( frameInfo.commandBuffer );
        }
    }

}