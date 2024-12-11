#include "keyboard_ctrl.hpp"

#define GLM_FORCE_RADIANS // forcing radians instead of degrees (no matter your os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE // forcing depth to be from 0 to 1
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <limits>

namespace BlockyVulkan {
    using glm::vec3;
    using glm::mat4;

    void KeyboardCtrl::MoveInPlaneXZ(GLFWwindow *window, float dt, GameObject &gameObj) {

        vec3 rot{0};

        if (glfwGetKey(window, keys.l_Right) == GLFW_PRESS) rot.y += 1.f;
        if (glfwGetKey(window, keys.l_Left) == GLFW_PRESS) rot.y -= 1.f;

        if (glfwGetKey(window, keys.l_Up) == GLFW_PRESS) rot.x += 1.f;
        if (glfwGetKey(window, keys.l_Down) == GLFW_PRESS) rot.x -= 1.f;

        if(glm::dot(rot, rot) > std::numeric_limits<float>::epsilon()) {
            gameObj.transform3D.rotation += lSpeed * dt * glm::normalize(rot);
        }

        // limit pitch values between about +/- 85ish deg
        gameObj.transform3D.rotation.x = glm::clamp(gameObj.transform3D.rotation.x, -1.5f, 1.5f);

        gameObj.transform3D.rotation.y = glm::mod(gameObj.transform3D.rotation.y, glm::two_pi<float>());
        

        float yaw = gameObj.transform3D.rotation.y;
        const vec3 forwardDir{sin(yaw), 0.f, cos(yaw)};
        const vec3 rightDir{forwardDir.z, 0.f, -forwardDir.x};
        const vec3 upDir{0.f, -1.f, 0.f};

        vec3 moveDir{0.f};
        if (glfwGetKey(window, keys.m_Forward) == GLFW_PRESS) moveDir += forwardDir;
        if (glfwGetKey(window, keys.m_Backward) == GLFW_PRESS) moveDir -= forwardDir;

        if (glfwGetKey(window, keys.m_Right) == GLFW_PRESS) moveDir += rightDir;
        if (glfwGetKey(window, keys.m_Left) == GLFW_PRESS) moveDir -= rightDir;

        if (glfwGetKey(window, keys.m_Up) == GLFW_PRESS) moveDir += upDir;
        if (glfwGetKey(window, keys.m_Down) == GLFW_PRESS) moveDir -= upDir;

        if (glm::dot(moveDir, moveDir) > std::numeric_limits<float>::epsilon()) {
            gameObj.transform3D.translation += mSpeed * dt * glm::normalize(moveDir);
        }

    }
}