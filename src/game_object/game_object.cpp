#include "game_object.hpp"

namespace BlockyVulkan {

    glm::mat4 Transform3D_Component::Mat4() {
        const float c3 = glm::cos(rotation.z);
        const float s3 = glm::sin(rotation.z);
        const float c2 = glm::cos(rotation.x);
        const float s2 = glm::sin(rotation.x);
        const float c1 = glm::cos(rotation.y);
        const float s1 = glm::sin(rotation.y);
        return mat4{
            {
                scale.x * (c1 * c3 + s1 * s2 * s3),
                scale.x * (c2 * s3),
                scale.x * (c1 * s2 * s3 - c3 * s1),
                0.0f,
            },
            {
                scale.y * (c3 * s1 * s2 - c1 * s3),
                scale.y * (c2 * c3),
                scale.y * (c1 * c3 * s2 + s1 * s3),
                0.0f,
            },
            {
                scale.z * (c2 * s1),
                scale.z * (-s2),
                scale.z * (c1 * c2),
                0.0f,
            },
            {
                translation.x,
                translation.y,
                translation.z,
                1.0f
            }
        };
    }

    mat3 Transform3D_Component::NormalMatrix() {
        const float c3 = glm::cos(rotation.z);
        const float s3 = glm::sin(rotation.z);
        const float c2 = glm::cos(rotation.x);
        const float s2 = glm::sin(rotation.x);
        const float c1 = glm::cos(rotation.y);
        const float s1 = glm::sin(rotation.y);

        const vec3 invScale = 1.f / scale;

        return mat3{
            {
                invScale.x *(c1 * c3 + s1 * s2 * s3),
                invScale.x *(c2 * s3),
                invScale.x *(c1 * s2 * s3 - c3 * s1),
            },
            {
                invScale.y * (c3 * s1 * s2 - c1 * s3),
                invScale.y * (c2 * c3),
                invScale.y * (c1 * c3 * s2 + s1 * s3),
            },
            {
                invScale.z * (c2 * s1),
                invScale.z * (-s2),
                invScale.z * (c1 * c2),
            }
        };
    }

    GameObject GameObject::MakePointLight(float power, float radius, vec3 color) {
        GameObject gameObj = GameObject::CreateGameObject();
        gameObj.color = color;
        gameObj.transform3D.scale.x = radius;
        gameObj.pointLight = std::make_unique<PointLight_Component>();
        gameObj.pointLight->power = power;
        
        return gameObj;
    }
}