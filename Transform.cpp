#include "Transform.h"

glm::mat4 Transform::GetMatrix() const
{
    glm::mat4 transform = glm::mat4(1.0f);

    transform = glm::translate(transform, Position);

    transform = glm::rotate(transform, Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::rotate(transform, Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    transform = glm::scale(transform, Scale);

    return transform;
}