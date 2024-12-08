#pragma once

#define GLM_FORCE_RADIANS // forcing radians instead of degrees (no matter your os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE // forcing depth to be from 0 to 1
#include <glm/glm.hpp>

#include "../model/model.hpp"

// std
#include <memory>

namespace BlockyVulkan {

struct Transform2D_Component {
    glm::vec2 translation{}; // (position offset)
    glm::vec2 scale{1.f, 1.f};
    float rotation;

    glm::mat2 mat2() {
        const float s = glm::sin(rotation);
        const float c = glm::cos(rotation);
        glm::mat2 rotMatrix{{c, s}, {-s, c}};

        glm::mat2 scaleMat{{scale.x, .0f},{.0f, scale.y}};
        return rotMatrix * scaleMat;
    }
};

class GameObject {
  public:
    using id_t = unsigned int;

    static GameObject createGameObject() {
        static id_t currentId = 0;
        return GameObject(currentId++);
    }

    GameObject(const GameObject &) = delete;
    GameObject &operator=(const GameObject &) = delete;
    GameObject(GameObject &&) = default;
    GameObject &operator=(GameObject &&) = default;

    const id_t GetId() {
        return id;
    }

    std::shared_ptr<Model> model{};
    glm::vec3 color{};
    Transform2D_Component transform2D{};

  private:
    GameObject(id_t objId) : id{objId} {};
    id_t id;
};
}
