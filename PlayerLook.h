#pragma once

#include "Component.h"
#include "Camera.h"

class PlayerLook : public Component
{
private:
	Camera* camera = nullptr;
	float sensitivity;

public:
	PlayerLook(Entity* entity, float sensitivity) : Component(entity), camera(nullptr), sensitivity(sensitivity) {}

	void Awake() override;
	void Update(float deltaTime) override;
};