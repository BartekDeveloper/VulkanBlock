#pragma once
#include "../device/device.hpp"
#include "../game_object/game_object.hpp"
#include "../model/model.hpp"
#include "../pipeline/pipeline.hpp"
#include "../swapchain/swap_chain.hpp"
#include "../window/window.hpp"

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

    FirstTest(const FirstTest &) = delete;
    FirstTest &operator=(const FirstTest &) = delete;

    void Run();

    void Sierpinski(std::vector<Model::Vertex> &vertices, int depth,
                    glm::vec2 left, glm::vec2 right, glm::vec2 top);

  private:
    void LoadGameObjects();
    void CreatePipelineLayout();
    void CreatePipeline();
    void CreateCommandBuffers();
    void FreeCommandBuffers();
    void DrawFrame();
    void RecreateSwapChain();
    void RecordCommandBuffer(int imageIndex);
    void RenderGameObjects(VkCommandBuffer commandBuffer);

    Window window{WIDTH, HEIGHT, "Hello Vulkan!"};
    Device device{window};
    std::unique_ptr<SwapChain> swapChain;
    std::unique_ptr<Pipeline> pipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<GameObject> gameObjects;
};
};  // namespace BlockyVulkan
