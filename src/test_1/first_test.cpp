#include "first_test.hpp"
#include "../controller/keyboard_ctrl.hpp"
#include "../camera/camera.hpp"
#include "../systems/simple_render_system/simple_render_system.hpp"
#include "../systems/point_light/point_light.hpp"
#include "../buffer/buffer.hpp"

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// std
#include <chrono>
#include <numeric>
#include <stdexcept>
#include <cassert>
#include <array>

namespace BlockyVulkan {
    using glm::vec2;
    using glm::vec3;
    using glm::vec4;
    using glm::mat3;
    using glm::mat4;

    // For not too big resize window acceleration
#define MAX_FRAME_TIME 50.f

    FirstTest::FirstTest() {
        globalPool = DescriptorPool::Builder(device)
            .SetMaxSets(SwapChain::MAX_FRAMES_IN_FLIGHT)
            .AddPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, SwapChain::MAX_FRAMES_IN_FLIGHT)
            .Build(); // Lol looks like I am programming Rust...(I am not)

        LoadGameObjects();
    }
    FirstTest::~FirstTest() {}

    void FirstTest::Run() {
        std::vector<std::unique_ptr<Buffer>> uboBuffers{ SwapChain::MAX_FRAMES_IN_FLIGHT };
        for (int i = 0; i < uboBuffers.size(); i++) {
            uboBuffers[i] = std::make_unique<Buffer>(
                device,
                sizeof(GlobalUBO),
                1,
                VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
                VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT
            );

            uboBuffers[i]->Map();
        }

        auto globalSetLayout = DescriptorSetLayout::Builder(device)
            .AddBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_ALL_GRAPHICS)
            .Build();

        std::vector<VkDescriptorSet> globalDescriptorSets(SwapChain::MAX_FRAMES_IN_FLIGHT);
        for (int i = 0; i < globalDescriptorSets.size(); i++) {
            auto bufferInfo = uboBuffers[i]->DescriptorInfo();

            DescriptorWriter(*globalSetLayout, *globalPool)
                .WriteBuffer(0, &bufferInfo)
                .Build(globalDescriptorSets[i]);
        }

        SimpleRenderSystem renderSystem{ device, renderer.GetSwapChainRenderPass(), globalSetLayout->GetDescriptorSetLayout() };
        PointLight pointLight{ device, renderer.GetSwapChainRenderPass(), globalSetLayout->GetDescriptorSetLayout() };

        // Initializing camera
        Camera camera{};

        // Making View Object (for making camera position reference this object)
        auto viewObj = GameObject::CreateGameObject();

        // Initializing keyboard control
        KeyboardCtrl camCtrl{};

        // Getting current time (for deltaTime calculations)
        auto currTime = std::chrono::high_resolution_clock::now();

        // Main GLFW loop
        while (!window.ShouldClose()) {
            glfwPollEvents();

            // Getting deltaTime
            auto newTime = std::chrono::high_resolution_clock::now();
            float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currTime).count();
            currTime = newTime;
            deltaTime = glm::min(deltaTime, MAX_FRAME_TIME);

            // Moving View Object (thus moving camera)
            camCtrl.MoveInPlaneXZ(window.GetGLFW_Window(), deltaTime, viewObj);
            camera.SetViewYXZ(viewObj.transform3D.translation, viewObj.transform3D.rotation);

            // aR is Aspect Ratio, but shortened, so its easier to write i guess... 
            float aR = renderer.GetAspectRatio();
            camera.SetPerspProj(glm::radians(45.f), aR, .1f, 128.f);

            // Begin frame
            if (auto commandBuffer = renderer.BeginFrame()) {
                // Getting current frame index (used for rendering)
                int frameIdx = renderer.GetFrameIndex();

                // Binding current info to frameInfo
                FrameInfo frameInfo{
                    frameIdx,
                    deltaTime,
                    commandBuffer,
                    camera,
                    globalDescriptorSets[frameIdx],
                    gameObjects
                };

                // Update

                // setting up ubo
                GlobalUBO ubo{};
                ubo.projection = camera.GetProj();
                ubo.view = camera.GetView();
                ubo.inverseView = camera.GetInvView();
                pointLight.Update(frameInfo, ubo);

                for (auto &kv : frameInfo.gameObjects) {
                    auto &obj = kv.second;
                    if(obj.pointLight == nullptr) continue;

                    auto rot = glm::rotate(mat4(1.f), -deltaTime / 2, { -0.15f, -.8f, .25f });
                    obj.transform3D.translation = vec3(rot * vec4(obj.transform3D.translation, 1.f));
                }


                uboBuffers[frameIdx]->WriteToBuffer(&ubo);
                uboBuffers[frameIdx]->Flush();

                // Rendering frame
                renderer.BeginSwapChainRenderPass(commandBuffer);

                
                // Order here matters!
                renderSystem.RenderGameObjects(frameInfo);
                pointLight.Render(frameInfo);

                // End frame
                // (from suffering lol)
                renderer.EndSwapChainRenderPass(commandBuffer);
                renderer.EndFrame();
            }
        }

        // Wait for GPU to finish its job
        vkDeviceWaitIdle(device.device());
    }

    void FirstTest::LoadGameObjects() {
        // Loading smooth vase model from obj, transforming and stuff...
        {
            std::shared_ptr<Model> smoothVaseModel = Model::CreateModelFromFile(device, "assets/models/smooth_vase.obj");
            auto smoothVase = GameObject::CreateGameObject();
            smoothVase.model = smoothVaseModel;
            smoothVase.transform3D.translation = { .1f, .5f, 1.5f };
            smoothVase.transform3D.scale = { 1.f, 1.f, 1.f };

            gameObjects.emplace(smoothVase.GetId(), std::move(smoothVase));
        }

        // Loading flat vase model(that ugly one) from obj, transforming and stuff...
        {
            std::shared_ptr<Model> flatVaseModel = Model::CreateModelFromFile(device, "assets/models/flat_vase.obj");
            auto  flatVase = GameObject::CreateGameObject();
            flatVase.model = flatVaseModel;
            flatVase.transform3D.translation = { -.1f, .5f, 1.5f };
            flatVase.transform3D.scale = { 1.f, 1.f, 1.f };

            gameObjects.emplace(flatVase.GetId(), std::move(flatVase));
        }

        // Loading flat ender dragon(stolen double(from author of this and from mojang/minecraft :) ) model from obj, transforming and stuff...
        {
            std::shared_ptr<Model> enderDragonModel = Model::CreateModelFromFile(device, "assets/models/ender_dragon.obj");
            auto enderDragon = GameObject::CreateGameObject();
            enderDragon.model = enderDragonModel;
            enderDragon.transform3D.translation = { -1.f, .5f, 5.f };
            enderDragon.transform3D.scale = { .01f, -.01f, .01f };
            enderDragon.transform3D.rotation.y = 90.f;

            gameObjects.emplace(enderDragon.GetId(), std::move(enderDragon));
        }

        // Loading floor  model from obj, transforming and stuff...
        {
            std::shared_ptr<Model> floorModel = Model::CreateModelFromFile(device, "assets/models/quad.obj");
            auto floor = GameObject::CreateGameObject();
            floor.model = floorModel;
            floor.transform3D.translation = { 0.f, 1.f, 0.f };
            floor.transform3D.scale = { 10.f, 1.f, 10.f };

            gameObjects.emplace(floor.GetId(), std::move(floor));
        }

        // Adding Point lights to scene
        {
            std::vector<vec3> lights{
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .1f, .1f, .8f }, // Blue
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }, // Dark red
                { .4f, .05f, .05f }  // Dark red
            };


            for (int i = 0; i < lights.size(); i++) {
                float fi = (float)i;
                auto pointLight = GameObject::MakePointLight(8.0f, 0.24f + .05f, lights[i]);
                auto rotate = glm::rotate(
                    mat4(1.f),
                    (fi * glm::two_pi<float>()) / lights.size(),
                    { -0.15f, -.8f, 0.25f }
                );
                pointLight.transform3D.translation = vec3(rotate * vec4(-4.f, -1.75f, -8.f, 1.f));
                gameObjects.emplace(pointLight.GetId(), std::move(pointLight));
            }
        }
    }
}
