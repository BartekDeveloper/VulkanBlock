#include "first_test.hpp"

#include "../simple_render_system/simple_render_system.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <array>
#include <iostream>
#include <cassert>

namespace BlockyVulkan {

FirstTest::FirstTest() { LoadGameObjects(); }
FirstTest::~FirstTest() {}

void FirstTest::Run() {
  // Get number of max push constant (irrelevant, beacuse i dont need more than specs 128 bytes, but still, just for fun, i guess...)
  std::cout << "Limit max push constant size: " << device.properties.limits.maxPushConstantsSize << "\n";


  SimpleRenderSystem renderSystem{device, renderer.GetSwapChainRenderPass()};

  while (!window.ShouldClose()) {
    glfwPollEvents();

    // Begin frame
    if( auto commandBuffer = renderer.BeginFrame() ) {
        renderer.BeginSwapChainRenderPass(commandBuffer);

        renderSystem.RenderGameObjects(commandBuffer, gameObjects);

        // End frame
        renderer.EndSwapChainRenderPass(commandBuffer);
        renderer.EndFrame();
    }
  }

  // Wait for GPU to finish its job
  vkDeviceWaitIdle(device.device());
}

void FirstTest::LoadGameObjects() {

  std::vector<Model::Vertex> verticies{
      {{-.75f, -.75f}, {1.f, .0f, .0f}},
      { { .75f, -.75f }, { .0f, .0f, 1.f } },
      {{-.0f, .75f}, {.0f, 1.f, .0f}}
    };

  auto model = std::make_shared<Model>(device, verticies);

  auto triangle = GameObject::createGameObject();
  triangle.model = model;
  triangle.color = {.2f, .1f, .8f};
  triangle.transform2D.translation.x = .2f;
  triangle.transform2D.scale = {2.f, .5f};
  triangle.transform2D.rotation = -.25f * glm::two_pi<float>();

  gameObjects.push_back(std::move(triangle));
}
}