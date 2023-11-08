#include "Camera.h"

#include "Entity.h"

Camera::Camera(Entity* entity, float fov, float aspectRatio, float near, float far) : Component(entity), FOV(fov), AspectRatio(aspectRatio), Near(near), Far(far)
{
	UpdateVectors();
}

void Camera::UpdateVectors()
{
    glm::vec3 forward = glm::vec3();
    forward.x = cos(glm::radians(entity->transform->Rotation.y)) * cos(glm::radians(entity->transform->Rotation.x));
    forward.y = sin(glm::radians(entity->transform->Rotation.x));
    forward.z = sin(glm::radians(entity->transform->Rotation.y)) * cos(glm::radians(entity->transform->Rotation.x));
    Forward = glm::normalize(forward);

    Right = glm::normalize(glm::cross(Forward, WorldUp));
    Up = glm::normalize(glm::cross(Right, Forward));
}

void Camera::CalculateViewMatrix()
{
    View = glm::lookAt(entity->transform->Position, entity->transform->Position + Forward, Up);
}

void Camera::CalculateProjectionMatrix()
{
    Projection = glm::perspective(glm::radians(FOV), AspectRatio, Near, Far);
}