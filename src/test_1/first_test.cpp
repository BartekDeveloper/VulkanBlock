#include "first_test.hpp"

// std
#include <array>
#include <stdexcept>

namespace BlockyVulkan {

FirstTest::FirstTest() {
  LoadModels();
  CreatePipelineLayout();
  RecreateSwapChain();
  CreateCommandBuffers();
}

FirstTest::~FirstTest() {
  vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);
}

void FirstTest::run() {
  while (!window.ShouldClose()) {
    glfwPollEvents();
    DrawFrame();
  }

  vkDeviceWaitIdle(device.device());
}

void FirstTest::Sierpinski(std::vector<Model::Vertex> &vertices, int depth,
                           glm::vec2 left, glm::vec2 right, glm::vec2 top) {
  if (depth <= 0) {
    vertices.push_back({top});
    vertices.push_back({right});
    vertices.push_back({left});
  } else {
    auto leftTop = 0.5f * (left + top);
    auto rightTop = 0.5f * (right + top);
    auto leftRight = 0.5f * (left + right);
    Sierpinski(vertices, depth - 1, left, leftRight, leftTop);
    Sierpinski(vertices, depth - 1, leftRight, right, rightTop);
    Sierpinski(vertices, depth - 1, leftTop, rightTop, top);
  }
}
void FirstTest::LoadModels() {
  // Sierpinski( vertices, 2, { -1.0f, -1.0f }, { 1.0f, -1.0f }, { 0.0f, 1.0f }
  // );

  std::vector<Model::Vertex> verticies{{{-.75f, -.75f}, {1.0f, .0f, .0f}},
                                       {{.75f, -.75f}, {.0f, 0.0f, 1.0f}},
                                       {{-.0f, .75f}, {.0f, 1.0f, .0f}}};

  model = std::make_unique<Model>(device, verticies);
}

void FirstTest::CreatePipelineLayout() {
  VkPipelineLayoutCreateInfo pipelineLayoutInfo{};

  pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
  pipelineLayoutInfo.setLayoutCount = 0;
  pipelineLayoutInfo.pSetLayouts = nullptr;
  pipelineLayoutInfo.pushConstantRangeCount = 0;
  pipelineLayoutInfo.pPushConstantRanges = nullptr;

  if (vkCreatePipelineLayout(device.device(), &pipelineLayoutInfo, nullptr,
                             &pipelineLayout) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create pipeline layout!");
  }
}

void FirstTest::CreatePipeline() {
    assert( swapChain != nullptr && "Cannot create pipeline before swap chain!" );
    assert( pipelineLayout != nullptr && "Cannot create pipeline before pipeline layout!" );
    
  PipelineConfigInfo pipelineConfig{};
  Pipeline::DefaultPipelineConfigInfo(pipelineConfig);
  pipelineConfig.renderPass = swapChain->getRenderPass();
  pipelineConfig.pipelineLayout = pipelineLayout;

  pipeline =
      std::make_unique<Pipeline>(device, "shaders/simple.vert.spv",
                                 "shaders/simple.frag.spv", pipelineConfig);
}

void FirstTest::RecreateSwapChain() {
  auto extent = window.getExtend();
  while (extent.width == 0 || extent.height == 0) {
    extent = window.getExtend();
    glfwWaitEvents();
  }

  vkDeviceWaitIdle(device.device());

  if (swapChain == nullptr) {
    swapChain = std::make_unique<SwapChain>(device, extent);
  } else {
    swapChain = std::make_unique<SwapChain>(device, extent, std::move(swapChain));
    if( swapChain->imageCount() != commandBuffers.size() ) {
        FreeCommandBuffers();
        CreateCommandBuffers();
    }
  }

  CreatePipeline();
}

void FirstTest::CreateCommandBuffers() {
  commandBuffers.resize(swapChain->imageCount());

  VkCommandBufferAllocateInfo allocInfo{};
  allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
  allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
  allocInfo.commandPool = device.getCommandPool();
  allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

  if (vkAllocateCommandBuffers(device.device(), &allocInfo,
                               commandBuffers.data()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to allocate command buffers");
  }
}

void FirstTest::FreeCommandBuffers() {
    vkFreeCommandBuffers( device.device(), device.getCommandPool(), static_cast<uint32_t>(commandBuffers.size()), commandBuffers.data());
    commandBuffers.clear();
}

void FirstTest::RecordCommandBuffer(int imageIndex) {
  VkCommandBufferBeginInfo beginInfo{};
  beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

  if (vkBeginCommandBuffer(commandBuffers[imageIndex], &beginInfo) !=
      VK_SUCCESS) {
    throw std::runtime_error("Failed to begin recording command buffer!");
  }

  VkRenderPassBeginInfo renderPassInfo{};
  renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
  renderPassInfo.renderPass = swapChain->getRenderPass();
  renderPassInfo.framebuffer = swapChain->getFrameBuffer(imageIndex);

  renderPassInfo.renderArea.offset = {0, 0};
  renderPassInfo.renderArea.extent = swapChain->getSwapChainExtent();

  std::array<VkClearValue, 2> clearValues{};
  clearValues[0].color = {.1f, .1f, .1f, 1.0f};
  clearValues[1].depthStencil = {1.0f, 0};

  renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
  renderPassInfo.pClearValues = clearValues.data();

  vkCmdBeginRenderPass(commandBuffers[imageIndex], &renderPassInfo,
                       VK_SUBPASS_CONTENTS_INLINE);

  // Creating viewport and scissor variables and configuring them
  VkViewport viewport{};
  viewport.x = .0f;
  viewport.y = .0f;
  viewport.width = static_cast<float>(swapChain->getSwapChainExtent().width);
  viewport.height = static_cast<float>(swapChain->getSwapChainExtent().height);
  viewport.minDepth = .0f;
  viewport.maxDepth = 1.0f;

  VkRect2D scissor({0, 0}, swapChain->getSwapChainExtent());

  // Setting up viewport and scissor so they are used
  vkCmdSetViewport(commandBuffers[imageIndex], 0, 1, &viewport);
  vkCmdSetScissor(commandBuffers[imageIndex], 0, 1, &scissor);

  pipeline->Bind(commandBuffers[imageIndex]);
  model->Bind(commandBuffers[imageIndex]);
  model->Draw(commandBuffers[imageIndex]);

  vkCmdEndRenderPass(commandBuffers[imageIndex]);
  if (vkEndCommandBuffer(commandBuffers[imageIndex]) != VK_SUCCESS) {
    throw std::runtime_error("Failed to record command buffer!");
  }
}

void FirstTest::DrawFrame() {
  uint32_t imageIdx;
  auto result = swapChain->acquireNextImage(&imageIdx);

  if (result == VK_ERROR_OUT_OF_DATE_KHR) {
    RecreateSwapChain();
    return;
  }

  if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
    throw std::runtime_error("Failed to aquire next swapchain image!");
  }

  RecordCommandBuffer(imageIdx);
  result =
      swapChain->submitCommandBuffers(&commandBuffers[imageIdx], &imageIdx);
  if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR ||
      window.WasWindowResized()) {
    window.ResetFlag_WindowResized();
    RecreateSwapChain();
    return;
  }
  if (result != VK_SUCCESS) {
    throw std::runtime_error("Failed to present swap chain image!");
  }
}

}  // namespace BlockyVulkan