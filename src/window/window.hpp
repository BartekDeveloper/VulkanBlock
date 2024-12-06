#pragma once

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <string>
#include <GLFW/glfw3.h>

namespace BlockyVulkan {

    class Window {
        public:
            Window( int w, int h, std::string name );
            ~Window();

            Window( const Window & ) = delete;
            Window &operator = ( const Window & ) = delete;

            bool ShouldClose() { return glfwWindowShouldClose( window ); }

            void CreateWindowSurface( VkInstance instance, VkSurfaceKHR *surface );

        private:
            void InitWindow();

            const int width;
            const int height;

            std::string name;
            GLFWwindow *window;
        };
}