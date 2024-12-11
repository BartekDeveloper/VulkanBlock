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
        mat4 transform{ 1.f };  // Initializes main diagonal, not every entry
        mat4 normalMatrix{1.f};
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
            std::make_unique<Pipeline>( device, "assets/shaders/simple.vert.spv",
                "assets/shaders/simple.frag.spv", pipelineConfig );
    }

    void SimpleRenderSystem::RenderGameObjects(VkCommandBuffer commandBuffer, std::vector<GameObject> &gameObjects, const Camera &camera) {
        pipeline->Bind( commandBuffer );

        auto projView = camera.GetProj() * camera.GetView();

        for( auto &obj : gameObjects ) {
            auto modelMatrix = obj.transform3D.Mat4();

            SimplePushConstantData push{};
            push.transform = projView * modelMatrix;
            push.normalMatrix = obj.transform3D.NormalMatrix();

            vkCmdPushConstants(
                commandBuffer, pipelineLayout,
                VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0,
                sizeof( SimplePushConstantData ), &push );

            obj.model->Bind( commandBuffer );
            obj.model->Draw( commandBuffer );
        }
    }

}