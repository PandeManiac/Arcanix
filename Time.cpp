#include "Time.h"
#include <GLFW/glfw3.h>

float Time::deltaTime = 0.0f;
float Time::lastFrameTime = 0.0f;

void Time::Update()
{
    float currentFrameTime = static_cast<float>(glfwGetTime());
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;
}

float Time::GetDeltaTime()
{
    return deltaTime;
}