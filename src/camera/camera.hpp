#pragma once

#define GLM_FORCE_RADIANS // forcing radians instead of degrees (no matter your os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE // forcing depth to be from 0 to 1
#include <glm/glm.hpp>

namespace BlockyVulkan {

    using glm::vec3;
    using glm::mat4;

    class Camera {
    public:
        void SetOrthoProj(
            float left,
            float right,
            float top,
            float bottom,
            float near,
            float far
        );

        void SetPerspProj(
            float fovy,
            float aspect,
            float near,
            float far
        );

        void SetViewDir(vec3 pos, vec3 dir, vec3 up = vec3{ 0.f, -1.f, 0.f });
        void SetViewTarget(vec3 pos, vec3 target, vec3 up = vec3{ 0.f, -1.f, 0.f });
        void SetViewYXZ(vec3 pos, vec3 rot);

        const mat4& GetProj() const { return projMat; }
        const mat4& GetView() const { return viewMat; }

    private:
        mat4 projMat{ 1.f };
        mat4 viewMat{ 1.f };

    };
}