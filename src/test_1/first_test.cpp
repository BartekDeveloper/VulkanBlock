#include "first_test.hpp"

#include "../controller/keyboard_ctrl.hpp"
#include "../camera/camera.hpp"
#include "../simple_render_system/simple_render_system.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <chrono>

namespace BlockyVulkan {
#define MAX_FRAME_TIME 1000.f

    FirstTest::FirstTest() { LoadGameObjects(); }
    FirstTest::~FirstTest() {}


    void FirstTest::Run() {
        SimpleRenderSystem renderSystem{ device, renderer.GetSwapChainRenderPass() };

        Camera camera{};

        auto viewObj = GameObject::CreateGameObject();
        KeyboardCtrl camCtrl{};

        auto currTime = std::chrono::high_resolution_clock::now();

        while (!window.ShouldClose()) {
            glfwPollEvents();

            auto newTime = std::chrono::high_resolution_clock::now();
            float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currTime).count();
            currTime = newTime;

            deltaTime = glm::min(deltaTime, MAX_FRAME_TIME);

            camCtrl.MoveInPlaneXZ(window.GetGLFW_Window(), deltaTime, viewObj);
            camera.SetViewYXZ(viewObj.transform3D.translation, viewObj.transform3D.rotation);

            // aR is Aspect Ratio, but shortened, so its easier to write i guess... 
            float aR = renderer.GetAspectRatio();
            //camera.SetOrthoProj(-aR, aR, -1, 1, -1, 1);
            camera.SetPerspProj(glm::radians(45.f), aR, .1f, 10.f);

            // Begin frame
            if (auto commandBuffer = renderer.BeginFrame()) {
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
    std::unique_ptr<Model> CreateCubeModel(Device &device, vec3 offset) {
        Model::Builder modelBuilder;

        modelBuilder.vertices = {
             // left face (white)
             {{-.5f, -.5f, -.5f}, {.9f, .9f, .9f}},
             {{-.5f, .5f, .5f}, {.9f, .9f, .9f}},
             {{-.5f, -.5f, .5f}, {.9f, .9f, .9f}},
             {{-.5f, .5f, -.5f}, {.9f, .9f, .9f}},

             // right face (yellow)
             {{.5f, -.5f, -.5f}, {.8f, .8f, .1f}},
             {{.5f, .5f, .5f}, {.8f, .8f, .1f}},
             {{.5f, -.5f, .5f}, {.8f, .8f, .1f}},
             {{.5f, .5f, -.5f}, {.8f, .8f, .1f}},

             // top face (orange, remember y axis points down)
             {{-.5f, -.5f, -.5f}, {.9f, .6f, .1f}},
             {{.5f, -.5f, .5f}, {.9f, .6f, .1f}},
             {{-.5f, -.5f, .5f}, {.9f, .6f, .1f}},
             {{.5f, -.5f, -.5f}, {.9f, .6f, .1f}},

             // bottom face (red)
             {{-.5f, .5f, -.5f}, {.8f, .1f, .1f}},
             {{.5f, .5f, .5f}, {.8f, .1f, .1f}},
             {{-.5f, .5f, .5f}, {.8f, .1f, .1f}},
             {{.5f, .5f, -.5f}, {.8f, .1f, .1f}},

             // nose face (blue)
             {{-.5f, -.5f, 0.5f}, {.1f, .1f, .8f}},
             {{.5f, .5f, 0.5f}, {.1f, .1f, .8f}},
             {{-.5f, .5f, 0.5f}, {.1f, .1f, .8f}},
             {{.5f, -.5f, 0.5f}, {.1f, .1f, .8f}},

             // tail face (green)
             {{-.5f, -.5f, -0.5f}, {.1f, .8f, .1f}},
             {{.5f, .5f, -0.5f}, {.1f, .8f, .1f}},
             {{-.5f, .5f, -0.5f}, {.1f, .8f, .1f}},
             {{.5f, -.5f, -0.5f}, {.1f, .8f, .1f}},
        };
        for (auto &v : modelBuilder.vertices) {
            v.position += offset;
        }

        modelBuilder.indices = {
            0,  1,  2,  0,  3,  1,  4,  5,  6,  4,  7,  5,  8,  9,  10, 8,  11, 9,
            12, 13, 14, 12, 15, 13, 16, 17, 18, 16, 19, 17, 20, 21, 22, 20, 23, 21
        };

        return std::make_unique<Model>(device, modelBuilder);
    }

    void FirstTest::LoadGameObjects() {
        std::shared_ptr<Model> model = CreateCubeModel(device, { .0f, .0f, .0f });

        auto cube = GameObject::CreateGameObject();
        cube.model = model;
        cube.transform3D.translation = { .0f, .0f, 2.5f };
        cube.transform3D.scale = { .5f, .5f, .5f };

        gameObjects.push_back(std::move(cube));
    }
}