#include "window.hpp"
#include <stdexcept>

namespace BlockyVulkan {
    Window::Window(int w, int h, std::string name)
        : width{w}, height{h}, name{name} {
      InitWindow();
    }

    Window::~Window() {
      if (window) glfwDestroyWindow(window);
      glfwTerminate();
    }

    void Window::InitWindow() {
      glfwInit();
      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    }

    void Window::CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if( glfwCreateWindowSurface( instance, window, nullptr, surface ) != VK_SUCCESS ) {
            throw std::runtime_error( "Failed to create window surface!" );
        }
    }

}  // namespace BlockyVulkan