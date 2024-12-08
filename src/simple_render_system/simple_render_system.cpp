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
        glm::mat4 transform{ 1.f };  // Initializes main diagonal, not every entry
        alignas( 16 ) glm::vec3 color;
    };

    SimpleRenderSystem::SimpleRenderSystem(Device &device, VkRenderPass renderPass) : device{device} {
        CreatePipelineLayout();
        CreatePipeline(renderPass);
    }

    SimpleRenderSystem::~SimpleRenderSystem() { vkDestroyPipelineLayout( device.device(), pipelineLayout, nullptr ); }

    void SimpleRenderSystem::CreatePipelineLayout() {
      // Creating push constants
        VkPushConstantRange pushConstRange{};
        pushConstRange.stageFlags =
            VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
        pushConstRange.offset = 0;
        pushConstRange.size = sizeof( SimplePushConstantData );

        // Setting up Layout info
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};

        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
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
            std::make_unique<Pipeline>( device, "shaders/simple.vert.spv",
                "shaders/simple.frag.spv", pipelineConfig );
    }

    void SimpleRenderSystem::RenderGameObjects( VkCommandBuffer commandBuffer, std::vector<GameObject> &gameObjects ) {
        pipeline->Bind( commandBuffer );

        for( auto &obj : gameObjects ) {
            obj.transform3D.rotation.y = glm::mod( obj.transform3D.rotation.y + 0.0001f, glm::two_pi<float>() );
            obj.transform3D.rotation.z = glm::mod( obj.transform3D.rotation.z + 0.000005f, glm::two_pi<float>() );

            SimplePushConstantData push{};
            push.color = obj.color;
            push.transform = obj.transform3D.Mat4();

            vkCmdPushConstants(
                commandBuffer, pipelineLayout,
                VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0,
                sizeof( SimplePushConstantData ), &push );

            obj.model->Bind( commandBuffer );
            obj.model->Draw( commandBuffer );
        }
    }

}