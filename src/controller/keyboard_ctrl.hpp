#pragma once

#include "../game_object/game_object.hpp"
#include "../window/window.hpp"

namespace BlockyVulkan {

    class KeyboardCtrl {
    public:
        struct KeyMap {
            //  Horizontal Movement
            int m_Left = GLFW_KEY_A;
            int m_Right = GLFW_KEY_D;
            int m_Forward = GLFW_KEY_W;
            int m_Backward = GLFW_KEY_S;

            // Vertical Movement
            int m_Up = GLFW_KEY_SPACE;
            int m_Down = GLFW_KEY_LEFT_SHIFT;

            // Looking... Movement(I guess it can be called that?)
            int l_Left = GLFW_KEY_LEFT; // arrow left
            int l_Right = GLFW_KEY_RIGHT; // arrow right
            int l_Up = GLFW_KEY_UP; // arrow up
            int l_Down = GLFW_KEY_DOWN; // arrow down
        };

        void MoveInPlaneXZ(GLFWwindow *window, float dt, GameObject &gameObj);

        KeyMap keys;
        float mSpeed{ 3.f };
        float lSpeed{ 1.5f };
    };
}