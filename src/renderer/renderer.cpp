#include "renderer.hpp"

// std
#include <array>
#include <iostream>
#include <stdexcept>

namespace BlockyVulkan {

    Renderer::Renderer( Window &window, Device &device ): window{ window }, device{ device } {
        RecreateSwapChain();
        CreateCommandBuffers();
    }

    Renderer::~Renderer() {
        FreeCommandBuffers();
    }

    void Renderer::RecreateSwapChain() {
        auto extent = window.getExtend();
        while( extent.width == 0 || extent.height == 0 ) {
            extent = window.getExtend();
            glfwWaitEvents();
        }

        vkDeviceWaitIdle( device.device() );

        if( swapChain == nullptr ) {
            swapChain = std::make_unique<SwapChain>( device, extent );
        } else {
            std::shared_ptr<SwapChain> oldSwapChain = std::move( swapChain );

            swapChain = std::make_unique<SwapChain>( device, extent, oldSwapChain );

            if( !oldSwapChain->compareSwapFormats( *swapChain.get() )) {
                throw std::runtime_error("Failed, swap chain image(or depth) format has changed!");
            }
        }

        // ---
    }

    void Renderer::CreateCommandBuffers() {
        commandBuffers.resize( SwapChain::MAX_FRAMES_IN_FLIGHT );

        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = device.getCommandPool();
        allocInfo.commandBufferCount = static_cast<uint32_t>( commandBuffers.size() );

        if( vkAllocateCommandBuffers( device.device(), &allocInfo,
            commandBuffers.data() ) != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to allocate command buffers" );
        }
    }

    void Renderer::FreeCommandBuffers() {
        vkFreeCommandBuffers( device.device(), device.getCommandPool(),
            static_cast<uint32_t>( commandBuffers.size() ),
            commandBuffers.data() );
        commandBuffers.clear();
    }

    VkCommandBuffer Renderer::BeginFrame() {
        assert(!didFrameStarted && "Can't call `BeginFrame` when frame already in progress!");

        auto result = swapChain->AcquireNextImage( &currImgIdx );

        if( result == VK_ERROR_OUT_OF_DATE_KHR ) {
            RecreateSwapChain();
            return nullptr;
        }

        if( result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR ) {
            throw std::runtime_error( "Failed to aquire next swapchain image!" );
        }

        didFrameStarted = true;

        auto commandBuffer__ = GetCurrentCommandBuffer();

        VkCommandBufferBeginInfo beginInfo{};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

        if( vkBeginCommandBuffer(commandBuffer__, &beginInfo ) !=
            VK_SUCCESS ) {
            throw std::runtime_error( "Failed to begin recording command buffer!" );
        }

        return commandBuffer__;
    }
    void Renderer::EndFrame() {
        assert(didFrameStarted && "Cannot call `EndFrame` when frame IS NOT in progress!");
        
        auto commandBuffer__ = GetCurrentCommandBuffer();
        if( vkEndCommandBuffer( commandBuffer__ ) != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to record command buffer!" );
        }

        auto result =
            swapChain->SubmitCommandBuffers( &commandBuffer__, &currImgIdx );
        if( result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR ||
            window.WasWindowResized() ) {
            window.ResetFlag_WindowResized();
            RecreateSwapChain();
        } else if( result != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to present swap chain image!" );
        }

        didFrameStarted = false;
        currFrameIdx = (currFrameIdx + 1) % SwapChain::MAX_FRAMES_IN_FLIGHT;
    }
    void Renderer::BeginSwapChainRenderPass( VkCommandBuffer commandBuffer ) {
        assert( didFrameStarted && "Cannot call `BeginSwapChainRenderPass` when frame IS NOT in progress!" );
        assert( commandBuffer == GetCurrentCommandBuffer() && "Can't begin render pass on command buffer from a different frame!");

        VkRenderPassBeginInfo renderPassInfo{};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassInfo.renderPass = swapChain->GetRenderPass();
        renderPassInfo.framebuffer = swapChain->GetFrameBuffer( currImgIdx );

        renderPassInfo.renderArea.offset = { 0, 0 };
        renderPassInfo.renderArea.extent = swapChain->GetSwapChainExtent();

        std::array<VkClearValue, 2> clearValues{};
        clearValues[0].color = { .0f, .0f, .0f, 1.f };
        clearValues[1].depthStencil = { 1.f, 0 };

        renderPassInfo.clearValueCount = static_cast<uint32_t>( clearValues.size() );
        renderPassInfo.pClearValues = clearValues.data();

        vkCmdBeginRenderPass( commandBuffer, &renderPassInfo,
            VK_SUBPASS_CONTENTS_INLINE );

        // Creating viewport and scissor variables and configuring them
        VkViewport viewport{};
        viewport.x = .0f;
        viewport.y = .0f;
        viewport.width = static_cast<float>( swapChain->GetSwapChainExtent().width );
        viewport.height = static_cast<float>( swapChain->GetSwapChainExtent().height );
        viewport.minDepth = .0f;
        viewport.maxDepth = 1.f;

        VkRect2D scissor( { 0, 0 }, swapChain->GetSwapChainExtent() );

        // Setting up viewport and scissor so they are used
        vkCmdSetViewport( commandBuffer, 0, 1, &viewport );
        vkCmdSetScissor( commandBuffer, 0, 1, &scissor );
    }
    void Renderer::EndSwapChainRenderPass( VkCommandBuffer commandBuffer ) {
        assert( didFrameStarted && "Cannot call `EndSwapChainRenderPass` when frame IS NOT in progress!" );
        assert( commandBuffer == GetCurrentCommandBuffer() && "Can't end render pass on command buffer from a different frame!" );

        vkCmdEndRenderPass( commandBuffer );
    }

}