#include "first_test.hpp"

// std
#include <stdexcept>
#include <array>

namespace BlockyVulkan {
    
    FirstTest::FirstTest() {
        CreatePipelineLayout();
        CreatePipeline();
        CreateCommandBuffers();
    }

    FirstTest::~FirstTest() {
        vkDestroyPipelineLayout( device.device(), pipelineLayout, nullptr );
    }

    void FirstTest::run() {
        while( !window.ShouldClose() ) {
            glfwPollEvents();
            DrawFrame();
        }
    }

    void FirstTest::CreatePipelineLayout() {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};

        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;

        if( vkCreatePipelineLayout( device.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to create pipeline layout!" );
        }
    }
     
    void FirstTest::CreatePipeline() {
        auto pipelineConfig = Pipeline::DefaultPipelineConfigInfo( swapChain.width(), swapChain.height() );
        pipelineConfig.renderPass = swapChain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        
        pipeline = std::make_unique<Pipeline>(device, "shaders/simple.vert.spv", "shaders/simple.frag.spv", pipelineConfig);
    }

    void FirstTest::CreateCommandBuffers() {
        commandBuffers.resize( swapChain.imageCount() );

        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = device.getCommandPool();
        allocInfo.commandBufferCount = static_cast<uint32_t>( commandBuffers.size() );

        if( vkAllocateCommandBuffers( device.device(), &allocInfo, commandBuffers.data() ) != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to allocate command buffers" );
        }

        for( int i = 0; i < commandBuffers.size(); i++ ) {
            VkCommandBufferBeginInfo beginInfo{};
            beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
            
            if( vkBeginCommandBuffer( commandBuffers[i], &beginInfo) != VK_SUCCESS ) {
                throw std::runtime_error( "Failed to begin recording command buffer!" );
            }

            VkRenderPassBeginInfo renderPassInfo{};
            renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            renderPassInfo.renderPass = swapChain.getRenderPass();
            renderPassInfo.framebuffer = swapChain.getFrameBuffer(i);

            renderPassInfo.renderArea.offset = { 0, 0 };
            renderPassInfo.renderArea.extent = swapChain.getSwapChainExtent();

            std::array<VkClearValue, 2> clearValues{};
            clearValues[0].color = { .1f, .1f, .1f, 1.0f };
            clearValues[1].depthStencil = { 1.0f, 0 };

            renderPassInfo.clearValueCount = static_cast<uint32_t>( clearValues.size() );
            renderPassInfo.pClearValues = clearValues.data();

            vkCmdBeginRenderPass( commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE );

            pipeline->Bind( commandBuffers[ i ] );
            vkCmdDraw( commandBuffers[ i ], 3, 1, 0, 0 );

            vkCmdEndRenderPass( commandBuffers[ i ] );
            if( vkEndCommandBuffer( commandBuffers[ i ] ) != VK_SUCCESS ) {
                throw std::runtime_error( "Failed to record command buffer!" );
            }
        }
    }

    void FirstTest::DrawFrame() {
        uint32_t imageIdx;
        auto result = swapChain.acquireNextImage( &imageIdx );

        if( result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR ) {
            throw std::runtime_error("Failed to aquire next swapchain image!");
        }

        result = swapChain.submitCommandBuffers( &commandBuffers[ imageIdx ], &imageIdx );
        if( result != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to present swap chain image!" );
        }
    }

}  // namespace BlockyVulkan