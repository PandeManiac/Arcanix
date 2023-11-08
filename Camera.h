#pragma once

#include "Component.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

class Camera : public Component
{
public:
	glm::vec3 Forward;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 Projection;
	glm::mat4 View;

	float FOV = 75.0f;
	float AspectRatio;
	float Near;
	float Far;

	Camera(Entity* entity, float fov, float aspectRatio, float near, float far);

	void UpdateVectors();

	void CalculateViewMatrix();
	void CalculateProjectionMatrix();
};