#pragma once
#define GLFW_INCLUDE_VULKAN

#include <cstdint>
#include <GLFW/glfw3.h>
#include <string>
#include <vulkan/vulkan_core.h>

namespace BlockyVulkan {

class Window {
  public:
    Window( int w, int h, std::string name );
    ~Window();

    Window( const Window & ) = delete;
    Window &operator = ( const Window & ) = delete;

    bool ShouldClose() {
        return glfwWindowShouldClose( window );
    }
    VkExtent2D getExtend() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
    bool WasWindowResized() {return frameBufferResized; }
    void ResetFlag_WindowResized() { frameBufferResized = false; }

    GLFWwindow* GetGLFW_Window() const { return window; }

    void CreateWindowSurface( VkInstance instance, VkSurfaceKHR *surface );

  private:
    static void FrameBufferResizeCallback( GLFWwindow *window, int width, int height );
    void InitWindow();

    int width;
    int height;
    bool frameBufferResized;

    std::string name;
    GLFWwindow *window;
};
}
