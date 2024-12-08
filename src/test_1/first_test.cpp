#include "first_test.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <array>
#include <iostream>
#include <stdexcept>

namespace BlockyVulkan {

struct SimplePushConstantData {
  glm::mat2 transform{1.f};  // Initializes main diagonal, not every entry
  glm::vec2 offset;
  alignas(16) glm::vec3 color;
};

FirstTest::FirstTest() {
  LoadGameObjects();
  CreatePipelineLayout();
  RecreateSwapChain();
  CreateCommandBuffers();
}

FirstTest::~FirstTest() {
  vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);
}

void FirstTest::Run() {
  std::cout << "Limit max push constant size: "
            << device.properties.limits.maxPushConstantsSize << "\n";

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
void FirstTest::LoadGameObjects() {
  // Sierpinski( vertices, 2, { -1.f, -1.f }, { 1.f, -1.f }, { .0f, 1.f }
  // );

  std::vector<Model::Vertex> verticies{{{-.75f, -.75f}, {1.f, .0f, .0f}},
                                       {{.75f, -.75f}, {.0f, .0f, 1.f}},
                                       {{-.0f, .75f}, {.0f, 1.f, .0f}}};

  auto model = std::make_shared<Model>(device, verticies);

  auto triangle = GameObject::createGameObject();
  triangle.model = model;
  triangle.color = {.2f, .1f, .8f};
  triangle.transform2D.translation.x = .2f;
  triangle.transform2D.scale = {2.f, .5f};
  triangle.transform2D.rotation = -.25f * glm::two_pi<float>();

  gameObjects.push_back(std::move(triangle));
}

void FirstTest::CreatePipelineLayout() {
  // Creating push constants
  VkPushConstantRange pushConstRange{};
  pushConstRange.stageFlags =
      VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
  pushConstRange.offset = 0;
  pushConstRange.size = sizeof(SimplePushConstantData);

  // Setting up Layout info
  VkPipelineLayoutCreateInfo pipelineLayoutInfo{};

  pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
  pipelineLayoutInfo.setLayoutCount = 0;
  pipelineLayoutInfo.pSetLayouts = nullptr;
  pipelineLayoutInfo.pushConstantRangeCount = 1;
  pipelineLayoutInfo.pPushConstantRanges = &pushConstRange;

  if (vkCreatePipelineLayout(device.device(), &pipelineLayoutInfo, nullptr,
                             &pipelineLayout) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create pipeline layout!");
  }
}

void FirstTest::CreatePipeline() {
  assert(swapChain != nullptr && "Cannot create pipeline before swap chain!");
  assert(pipelineLayout != nullptr &&
         "Cannot create pipeline before pipeline layout!");

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
    swapChain =
        std::make_unique<SwapChain>(device, extent, std::move(swapChain));
    if (swapChain->imageCount() != commandBuffers.size()) {
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
  vkFreeCommandBuffers(device.device(), device.getCommandPool(),
                       static_cast<uint32_t>(commandBuffers.size()),
                       commandBuffers.data());
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
  clearValues[0].color = {.1f, .1f, .1f, 1.f};
  clearValues[1].depthStencil = {1.f, 0};

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
  viewport.maxDepth = 1.f;

  VkRect2D scissor({0, 0}, swapChain->getSwapChainExtent());

  // Setting up viewport and scissor so they are used
  vkCmdSetViewport(commandBuffers[imageIndex], 0, 1, &viewport);
  vkCmdSetScissor(commandBuffers[imageIndex], 0, 1, &scissor);

  RenderGameObjects(commandBuffers[imageIndex]);

  vkCmdEndRenderPass(commandBuffers[imageIndex]);
  if (vkEndCommandBuffer(commandBuffers[imageIndex]) != VK_SUCCESS) {
    throw std::runtime_error("Failed to record command buffer!");
  }
}

void FirstTest::RenderGameObjects(VkCommandBuffer commandBuffer) {
  pipeline->Bind(commandBuffer);

  for (auto &obj : gameObjects) {
      obj.transform2D.rotation = glm::mod(obj.transform2D.rotation + 0.001f, glm::two_pi<float>());

    SimplePushConstantData push{};
    push.offset = obj.transform2D.translation;
    push.color = obj.color;
    push.transform = obj.transform2D.mat2();

    vkCmdPushConstants(
        commandBuffer, pipelineLayout,
        VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0,
        sizeof(SimplePushConstantData), &push);

    obj.model->Bind(commandBuffer);
    obj.model->Draw(commandBuffer);
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