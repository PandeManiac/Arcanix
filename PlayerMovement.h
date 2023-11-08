#pragma once

#include "Component.h"

#include "Camera.h"
#include <glm/glm.hpp>

class PlayerMovement : public Component
{
private:
	Camera* camera = nullptr;
	float moveSpeed;

public:
	PlayerMovement(Entity* entity, float moveSpeed) : Component(entity), camera(nullptr), moveSpeed(moveSpeed) {}

	void Awake() override;
	void Update(float deltaTime) override;

private:
	void Move(glm::vec3 direction, float deltaTime);
};