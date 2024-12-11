#include "first_test.hpp"

#include "../camera/camera.hpp"
#include "../simple_render_system/simple_render_system.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <array>
#include <cassert>
#include <iostream>

namespace BlockyVulkan {

    FirstTest::FirstTest() { LoadGameObjects(); }
    FirstTest::~FirstTest() {}

    void FirstTest::Run() {
      /* Get number of max push constant(irrelevant, beacuse i dont need more than
       specs 128 bytes, but still, just for fun, i guess...) */
        std::cout << "Limit max push constant size: "
            << device.properties.limits.maxPushConstantsSize << "\n";

        SimpleRenderSystem renderSystem{ device, renderer.GetSwapChainRenderPass() };

        Camera camera{};
        //camera.SetViewDir(vec3{0.f}, vec3{.5f, 0.f, 1.f});
        camera.SetViewTarget(vec3{-1.f, -2.f, -20.f}, vec3{0.f, 0.f, 2.5f});

        while ( !window.ShouldClose() ) {
            glfwPollEvents();

            // aR is Aspect Ratio, but shortened, so its easier to write i guess... 
            float aR = renderer.GetAspectRatio();
            //camera.SetOrthoProj(-aR, aR, -1, 1, -1, 1);
            camera.SetPerspProj(glm::radians(45.f), aR, .1f, 10.f);

            // Begin frame
            if ( auto commandBuffer = renderer.BeginFrame() ) {
                renderer.BeginSwapChainRenderPass(commandBuffer);

                renderSystem.RenderGameObjects(commandBuffer, gameObjects, camera);

                // End frame
                renderer.EndSwapChainRenderPass(commandBuffer);
                renderer.EndFrame();
            }
        }

        // Wait for GPU to finish its job
        vkDeviceWaitIdle(device.device());
    }

    // temporary helper function, creates a 1x1x1 cube centered at offset
    std::unique_ptr<Model> CreateCubeModel(Device &device, glm::vec3 offset) {
        std::vector<Model::Vertex> vertices{

            // left face (white)
            {{-.5f, -.5f, -.5f}, {.9f, .9f, .9f}},
            {{-.5f, .5f, .5f}, {.9f, .9f, .9f}},
            {{-.5f, -.5f, .5f}, {.9f, .9f, .9f}},
            {{-.5f, -.5f, -.5f}, {.9f, .9f, .9f}},
            {{-.5f, .5f, -.5f}, {.9f, .9f, .9f}},
            {{-.5f, .5f, .5f}, {.9f, .9f, .9f}},

            // right face (yellow)
            {{.5f, -.5f, -.5f}, {.8f, .8f, .1f}},
            {{.5f, .5f, .5f}, {.8f, .8f, .1f}},
            {{.5f, -.5f, .5f}, {.8f, .8f, .1f}},
            {{.5f, -.5f, -.5f}, {.8f, .8f, .1f}},
            {{.5f, .5f, -.5f}, {.8f, .8f, .1f}},
            {{.5f, .5f, .5f}, {.8f, .8f, .1f}},

            // top face (orange, remember y axis points down)
            {{-.5f, -.5f, -.5f}, {.9f, .6f, .1f}},
            {{.5f, -.5f, .5f}, {.9f, .6f, .1f}},
            {{-.5f, -.5f, .5f}, {.9f, .6f, .1f}},
            {{-.5f, -.5f, -.5f}, {.9f, .6f, .1f}},
            {{.5f, -.5f, -.5f}, {.9f, .6f, .1f}},
            {{.5f, -.5f, .5f}, {.9f, .6f, .1f}},

            // bottom face (red)
            {{-.5f, .5f, -.5f}, {.8f, .1f, .1f}},
            {{.5f, .5f, .5f}, {.8f, .1f, .1f}},
            {{-.5f, .5f, .5f}, {.8f, .1f, .1f}},
            {{-.5f, .5f, -.5f}, {.8f, .1f, .1f}},
            {{.5f, .5f, -.5f}, {.8f, .1f, .1f}},
            {{.5f, .5f, .5f}, {.8f, .1f, .1f}},

            // nose face (blue)
            {{-.5f, -.5f, 0.5f}, {.1f, .1f, .8f}},
            {{.5f, .5f, 0.5f}, {.1f, .1f, .8f}},
            {{-.5f, .5f, 0.5f}, {.1f, .1f, .8f}},
            {{-.5f, -.5f, 0.5f}, {.1f, .1f, .8f}},
            {{.5f, -.5f, 0.5f}, {.1f, .1f, .8f}},
            {{.5f, .5f, 0.5f}, {.1f, .1f, .8f}},

            // tail face (green)
            {{-.5f, -.5f, -0.5f}, {.1f, .8f, .1f}},
            {{.5f, .5f, -0.5f}, {.1f, .8f, .1f}},
            {{-.5f, .5f, -0.5f}, {.1f, .8f, .1f}},
            {{-.5f, -.5f, -0.5f}, {.1f, .8f, .1f}},
            {{.5f, -.5f, -0.5f}, {.1f, .8f, .1f}},
            {{.5f, .5f, -0.5f}, {.1f, .8f, .1f}},

        };
        for ( auto &v : vertices ) {
            v.position += offset;
        }
        return std::make_unique<Model>(device, vertices);
    }

    void FirstTest::LoadGameObjects() {
        std::shared_ptr<Model> model = CreateCubeModel(device, { .0f, .0f, .0f });

        auto cube = GameObject::createGameObject();
        cube.model = model;
        cube.transform3D.translation = { .0f, .0f, 2.5f };
        cube.transform3D.scale = { .5f, .5f, .5f };

        gameObjects.push_back(std::move(cube));
    }
}  // namespace BlockyVulkan