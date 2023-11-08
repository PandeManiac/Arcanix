#include "Input.h"

int Input::previousKeyStates[GLFW_KEY_LAST] = { 0 };
int Input::currentKeyStates[GLFW_KEY_LAST] = { 0 };

glm::vec2 Input::MousePosition = glm::vec2(0.0f, 0.0f);
glm::vec2 Input::MouseDelta = glm::vec2(0.0f, 0.0f);
bool Input::FirstMouse = true;

void Input::Update()
{
    for (int i = 0; i < GLFW_KEY_LAST; ++i)
    {
        previousKeyStates[i] = currentKeyStates[i];
        currentKeyStates[i] = glfwGetKey(Window::GameWindow, i);
    }
}

bool Input::GetKeyDown(Keys key)
{
    int keyCode = static_cast<int>(key);
    return currentKeyStates[keyCode] == GLFW_PRESS && previousKeyStates[keyCode] != GLFW_PRESS;
}

bool Input::GetKeyUp(Keys key)
{
    int keyCode = static_cast<int>(key);
    return currentKeyStates[keyCode] == GLFW_RELEASE && previousKeyStates[keyCode] != GLFW_RELEASE;
}

bool Input::GetKey(Keys key)
{
    int keyCode = static_cast<int>(key);
    return currentKeyStates[keyCode] == GLFW_PRESS || currentKeyStates[keyCode] == GLFW_REPEAT;
}

void Input::UpdateMousePosition(float x, float y)
{
    if (FirstMouse)
    {
        MousePosition.x = x;
        MousePosition.y = y;
        FirstMouse = false;
    }

    MouseDelta.x = x - MousePosition.x;
    MouseDelta.y = MousePosition.y - y;
    MousePosition.x = x;
    MousePosition.y = y;
}