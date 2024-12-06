#pragma once
#include "../window/window.hpp"
#include "../pipeline/pipeline.hpp"

namespace BlockyVulkan {
    class FirstTest {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
            Window window{ WIDTH, HEIGHT, "Hello Vulkan!" };
            Pipeline pipeline{ "shaders/simple.vert.spv", "shaders/simple.frag.spv" };
    };
}