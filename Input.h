#pragma once

#include "Window.h"
#include "Keys.h"

class Input
{
private:
    static int previousKeyStates[GLFW_KEY_LAST];
    static int currentKeyStates[GLFW_KEY_LAST];

    Input() {}

public:
    static glm::vec2 MousePosition;
    static glm::vec2 MouseDelta;
    static bool FirstMouse;

    static void Update();

    static bool GetKeyDown(Keys key);
    static bool GetKeyUp(Keys key);
    static bool GetKey(Keys key);

    static void UpdateMousePosition(float x, float y);
};