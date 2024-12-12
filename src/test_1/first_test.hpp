#pragma once
#include "../device/device.hpp"
#include "../game_object/game_object.hpp"
#include "../model/model.hpp"
#include "../window/window.hpp"
#include "../renderer/renderer.hpp"
#include "../descriptors/descriptors.hpp"

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
     
  private:
    void LoadGameObjects();

    Window window{WIDTH, HEIGHT, "Hello Vulkan!"};
    Device device{window};
    Renderer renderer{window, device};

    // Note: Order here matters!
    std::unique_ptr<DescriptorPool> globalPool{};
    GameObject::Map gameObjects;
};
};