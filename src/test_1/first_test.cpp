#include "test_1.hpp"

namespace BlockyVulkan {
    void FirstTest::run() {
        while( !window.ShouldClose() ) {
            glfwPollEvents();
        }
    }
}  // namespace BlockyVulkan