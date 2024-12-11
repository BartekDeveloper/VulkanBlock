#pragma once

#include "../camera/camera.hpp"
#include "../device/device.hpp"
#include "../game_object/game_object.hpp"
#include "../pipeline/pipeline.hpp"


// std
#include <memory>
#include <vector>

namespace BlockyVulkan {
    class SimpleRenderSystem {
    public:

        SimpleRenderSystem(Device &device, VkRenderPass renderPass);
        ~SimpleRenderSystem();

        SimpleRenderSystem(const SimpleRenderSystem &) = delete;
        SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

        void RenderGameObjects(VkCommandBuffer commandBuffer, std::vector<GameObject> &gameObjects, const Camera &camera);

    private:
        void CreatePipelineLayout();
        void CreatePipeline(VkRenderPass renderPass);

        Device &device;

        std::unique_ptr<Pipeline> pipeline;
        VkPipelineLayout pipelineLayout;
    };
};