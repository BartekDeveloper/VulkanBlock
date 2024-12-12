#pragma once

#include "../../camera/camera.hpp"
#include "../../device/device.hpp"
#include "../../game_object/game_object.hpp"
#include "../../pipeline/pipeline.hpp"
#include "../../frame_info/frame_info.hpp"


// std
#include <memory>
#include <vector>

namespace BlockyVulkan {
    class PointLight {
    public:

        PointLight(Device &device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
        ~PointLight();

        PointLight(const PointLight &) = delete;
        PointLight &operator=(const PointLight &) = delete;

        void Render(FrameInfo &frameInfo);

    private:
        void CreatePipelineLayout(VkDescriptorSetLayout globalSetLayout);
        void CreatePipeline(VkRenderPass renderPass);

        Device &device;

        std::unique_ptr<Pipeline> pipeline;
        VkPipelineLayout pipelineLayout;
    };
};