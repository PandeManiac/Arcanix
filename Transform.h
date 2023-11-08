#pragma once

#include "Component.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Transform : public Component
{
public:
    glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 Scale = glm::vec3(1.0f, 1.0f, 1.0f);

    Transform(Entity* entity) : Component(entity) {}

    glm::mat4 GetMatrix() const;
};