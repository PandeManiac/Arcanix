#pragma once

class Time
{
private:
    static float deltaTime;
    static float lastFrameTime;

public:
    static void Update();
    static float GetDeltaTime();
};
