#include "PlayerLook.h"

#include "Entity.h"
#include "Input.h"

void PlayerLook::Awake()
{
    camera = entity->GetComponent<Camera>();
    glfwSetInputMode(Window::GameWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void PlayerLook::Update(float deltaTime)
{
    glm::vec2 mouseDelta = Input::MouseDelta;
    Input::MouseDelta = glm::vec2(0.0f, 0.0f);

    mouseDelta *= sensitivity;

    camera->entity->transform->Rotation.x += mouseDelta.y;
    camera->entity->transform->Rotation.y += mouseDelta.x;

    camera->entity->transform->Rotation.x = glm::clamp(camera->entity->transform->Rotation.x, -89.0f, 89.0f);
    camera->entity->transform->Rotation.y = fmod(camera->entity->transform->Rotation.y, 360.0f);

    if (camera->entity->transform->Rotation.y < 0.0f)
    {
        camera->entity->transform->Rotation.y += 360.0f;
    }

    camera->UpdateVectors();
}