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

    void FirstTest::LoadGameObjects() {
        std::shared_ptr<Model> model = Model::CreateModelFromFile(device, "assets/models/smooth_vase.obj");

        auto gameObj = GameObject::CreateGameObject();
        gameObj.model = model;
        gameObj.transform3D.translation = { .0f, .0f, .5f };
        gameObj.transform3D.scale = { 1.f, 1.f, 1.f };

        gameObjects.push_back(std::move(gameObj));
    }
}