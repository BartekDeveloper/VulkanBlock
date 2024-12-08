#pragma once
#include "../device/device.hpp"
#include "../model/model.hpp"
#include "../swapchain/swap_chain.hpp"
#include "../window/window.hpp"

// std
#include <memory>
#include <vector>
#include <cassert>

namespace BlockyVulkan {
    class Renderer {
        public:

        Renderer(Window &window, Device &device);
        ~Renderer();

        Renderer( const Renderer & ) = delete;
        Renderer &operator=( const Renderer & ) = delete;

        const VkRenderPass GetSwapChainRenderPass() const { return swapChain->GetRenderPass(); }
        const bool IsFrameInProgress() const { return didFrameStarted; }

        const VkCommandBuffer GetCurrentCommandBuffer() const {
            assert(didFrameStarted && "Cannot get command buffer when frame not in progress!");
            return commandBuffers[currFrameIdx];
        }

        const int GetFrameIndex() const {
            assert(didFrameStarted && "Cannot get `frame index` when frame not in progress");
            return currFrameIdx;
        }

        VkCommandBuffer BeginFrame();
        void EndFrame();
        void BeginSwapChainRenderPass( VkCommandBuffer commandBuffer );
        void EndSwapChainRenderPass( VkCommandBuffer commandBuffer );

        private:
        void CreateCommandBuffers();
        void FreeCommandBuffers();
        void RecreateSwapChain();

        Window &window;
        Device &device;
        std::unique_ptr<SwapChain> swapChain;
        std::vector<VkCommandBuffer> commandBuffers;

        uint32_t currImgIdx;
        int currFrameIdx{0};
        bool didFrameStarted{false};
    };
};
