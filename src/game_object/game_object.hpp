#pragma once

#define GLM_FORCE_RADIANS  // forcing radians instead of degrees (no matter your
                           // os settings)
#define GLM_FORCE_DEPTH_ZERO_TO_ONE  // forcing depth to be from 0 to 1
#include <glm/glm.hpp>

#include "../model/model.hpp"

// std
#include <memory>

namespace BlockyVulkan {

struct Transform3D_Component {
  glm::vec3 translation{};  // (position offset)
  glm::vec3 scale{1.f, 1.f, 1.f};
  glm::vec3 rotation;

  // Matrix corresponding to translate * Ry * Rx * Ry * scale transformation
  // Rotation convention usees tail-bryan angles with axis order Y(1), X(2),
  // Z(3) Matrix corrsponds to Translate * Ry * Rx * Rz * Scale
  // https://en.wikipedia.org/wiki/Euler_angles#Rotation_matrix
  glm::mat4 Mat4() {
    const float c3 = glm::cos(rotation.z);
    const float s3 = glm::sin(rotation.z);
    const float c2 = glm::cos(rotation.x);
    const float s2 = glm::sin(rotation.x);
    const float c1 = glm::cos(rotation.y);
    const float s1 = glm::sin(rotation.y);
    return glm::mat4{
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

  const id_t GetId() const { return id; }

  std::shared_ptr<Model> model{};
  glm::vec3 color{};
  Transform3D_Component transform3D{};

 private:
  GameObject(id_t objId) : id{objId} {};
  id_t id;
};
}  // namespace BlockyVulkan
