#include "camera.hpp"

// std
#include <cmath>
#include <limits>
#include <cassert>

namespace BlockyVulkan {

    void Camera::SetOrthoProj(
        float left, float right, float top, float bottom, float near, float far) {
        projMat = mat4{ 1.0f };
        projMat[0][0] = 2.f / (right - left);
        projMat[1][1] = 2.f / (bottom - top);
        projMat[2][2] = 1.f / (far - near);
        projMat[3][0] = -(right + left) / (right - left);
        projMat[3][1] = -(bottom + top) / (bottom - top);
        projMat[3][2] = -near / (far - near);
    }

    void Camera::SetPerspProj(float fovy, float aspect, float near, float far) {
        assert(glm::abs(aspect - std::numeric_limits<float>::epsilon()) > 0.0f);
        auto aspect_nominator = aspect;
        auto aspect_denominator = 1.0f;
        if ( aspect < 1.0f ) {
            aspect_nominator = 1.0f;
            aspect_denominator = 1 / aspect;
        }
        const float tanHalfFovy = tan(fovy / 2.f);
        projMat = mat4{ 0.0f };
        projMat[0][0] = 1.f / (aspect_nominator * tanHalfFovy);
        projMat[1][1] = 1.f / (aspect_denominator * tanHalfFovy);
        projMat[2][2] = far / (far - near);
        projMat[2][3] = 1.f;
        projMat[3][2] = -(far * near) / (far - near);
    }

    void Camera::SetViewDir(vec3 pos, vec3 Dir, vec3 up) {
        const vec3 w{ glm::normalize(Dir) };
        const vec3 u{ glm::normalize(glm::cross(w, up)) };
        const vec3 v{ glm::cross(w, u) };

        viewMat = mat4{ 1.f };
        viewMat[0][0] = u.x;
        viewMat[1][0] = u.y;
        viewMat[2][0] = u.z;
        viewMat[0][1] = v.x;
        viewMat[1][1] = v.y;
        viewMat[2][1] = v.z;
        viewMat[0][2] = w.x;
        viewMat[1][2] = w.y;
        viewMat[2][2] = w.z;
        viewMat[3][0] = -glm::dot(u, pos);
        viewMat[3][1] = -glm::dot(v, pos);
        viewMat[3][2] = -glm::dot(w, pos);

        inverseViewMat = glm::mat4{ 1.f };
        inverseViewMat[0][0] = u.x;
        inverseViewMat[0][1] = u.y;
        inverseViewMat[0][2] = u.z;
        inverseViewMat[1][0] = v.x;
        inverseViewMat[1][1] = v.y;
        inverseViewMat[1][2] = v.z;
        inverseViewMat[2][0] = w.x;
        inverseViewMat[2][1] = w.y;
        inverseViewMat[2][2] = w.z;
        inverseViewMat[3][0] = pos.x;
        inverseViewMat[3][1] = pos.y;
        inverseViewMat[3][2] = pos.z;
    }

    void Camera::SetViewTarget(vec3 pos, vec3 target, vec3 up) {
        auto targetSubPos = target - pos;
        SetViewDir(pos, targetSubPos, up);
    }

    void Camera::SetViewYXZ(vec3 pos, vec3 rot) {
        const float c3 = glm::cos(rot.z);
        const float s3 = glm::sin(rot.z);
        const float c2 = glm::cos(rot.x);
        const float s2 = glm::sin(rot.x);
        const float c1 = glm::cos(rot.y);
        const float s1 = glm::sin(rot.y);
        const vec3 u{ (c1 * c3 + s1 * s2 * s3), (c2 * s3), (c1 * s2 * s3 - c3 * s1) };
        const vec3 v{ (c3 * s1 * s2 - c1 * s3), (c2 * c3), (c1 * c3 * s2 + s1 * s3) };
        const vec3 w{ (c2 * s1), (-s2), (c1 * c2) };
        viewMat = mat4{ 1.f };
        viewMat[0][0] = u.x;
        viewMat[1][0] = u.y;
        viewMat[2][0] = u.z;
        viewMat[0][1] = v.x;
        viewMat[1][1] = v.y;
        viewMat[2][1] = v.z;
        viewMat[0][2] = w.x;
        viewMat[1][2] = w.y;
        viewMat[2][2] = w.z;
        viewMat[3][0] = -glm::dot(u, pos);
        viewMat[3][1] = -glm::dot(v, pos);
        viewMat[3][2] = -glm::dot(w, pos);

        inverseViewMat = glm::mat4{ 1.f };
        inverseViewMat[0][0] = u.x;
        inverseViewMat[0][1] = u.y;
        inverseViewMat[0][2] = u.z;
        inverseViewMat[1][0] = v.x;
        inverseViewMat[1][1] = v.y;
        inverseViewMat[1][2] = v.z;
        inverseViewMat[2][0] = w.x;
        inverseViewMat[2][1] = w.y;
        inverseViewMat[2][2] = w.z;
        inverseViewMat[3][0] = pos.x;
        inverseViewMat[3][1] = pos.y;
        inverseViewMat[3][2] = pos.z;
    }
}