#include "PlayerMovement.h"

#include "Entity.h"
#include "Input.h"
#include "Camera.h"

void PlayerMovement::Awake()
{
    camera = entity->GetComponent<Camera>();
}

void PlayerMovement::Update(float deltaTime)
{
    if (Input::GetKey(Keys::W))
    {
        glm::vec3 forwardFlat = glm::normalize(glm::vec3(camera->Forward.x, 0.0f, camera->Forward.z));
        Move(forwardFlat, deltaTime);
    }

    if (Input::GetKey(Keys::S))
    {
        glm::vec3 backwardFlat = glm::normalize(glm::vec3(-camera->Forward.x, 0.0f, -camera->Forward.z));
        Move(backwardFlat, deltaTime);
    }

    if (Input::GetKey(Keys::A))
    {
        Move(-camera->Right, deltaTime);
    }

    if (Input::GetKey(Keys::D))
    {
        Move(camera->Right, deltaTime);
    }
}

void PlayerMovement::Move(glm::vec3 direction, float deltaTime)
{
    glm::vec3 movement = direction * moveSpeed * deltaTime;
    entity->transform->Position += movement;
}
