#pragma once

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>

#include "../model/model.hpp"


#include <unordered_map>
#include <memory>

using glm::mat4;
using glm::mat3;
using glm::vec3;

namespace BlockyVulkan {

    struct Transform3D_Component {
        vec3 translation{};  // (position offset)
        vec3 scale{ 1.f, 1.f, 1.f };
        vec3 rotation;

        // Matrix corresponding to translate * Ry * Rx * Ry * scale transformation
        // Rotation convention usees tail-bryan angles with axis order Y(1), X(2),
        // Z(3) Matrix corrsponds to Translate * Ry * Rx * Rz * Scale
        // https://en.wikipedia.org/wiki/Euler_angles#Rotation_matrix
        mat4 Mat4();
        mat3 NormalMatrix();
    };

    struct PointLight_Component {
        float power = 1.0f;
    };

    class GameObject {
    public:
        using id_t = unsigned int;
        using Map = std::unordered_map<id_t, GameObject>;

        static GameObject CreateGameObject() { static id_t currentId = 0; return GameObject(currentId++); }
        static GameObject MakePointLight(float power = 4.0f, float radius = 0.1f, vec3 color = vec3{1.f});

        GameObject(const GameObject &) = delete;
        GameObject &operator=(const GameObject &) = delete;
        GameObject(GameObject &&) = default;
        GameObject &operator=(GameObject &&) = default;

        const id_t GetId() const { return id; }

        vec3 color{};
        Transform3D_Component transform3D{};

        // Optional Components
        std::shared_ptr<Model> model{};
        std::unique_ptr<PointLight_Component> pointLight = nullptr;

    private:
        GameObject(id_t objId) : id{objId} {};
        id_t id;
    };
}
