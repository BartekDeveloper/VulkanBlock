#pragma once
#include "../device/device.hpp"
#include "../pipeline/pipeline.hpp"
#include "../window/window.hpp"
#include "../swapchain/swap_chain.hpp"

// std
#include <memory>
#include <vector>

namespace BlockyVulkan {
    class FirstTest {
     public:
      static constexpr int WIDTH{800};
      static constexpr int HEIGHT{600};

      FirstTest();
      ~FirstTest();

      FirstTest( const FirstTest & ) = delete;
      FirstTest &operator = ( const FirstTest & ) = delete;

      void run();

     private:
         void CreatePipelineLayout();
         void CreatePipeline();
         void CreateCommandBuffers();
         void DrawFrame();

          Window window{WIDTH, HEIGHT, "Hello Vulkan!"};
          Device device{window};
          SwapChain swapChain{device, window.getExtend()};
          std::unique_ptr<Pipeline> pipeline;
          VkPipelineLayout pipelineLayout;
          std::vector<VkCommandBuffer> commandBuffers;
    };
};  // namespace BlockyVulkan
