#pragma once

class Entity;

class Component
{
public:
    Entity* entity = nullptr;

public:
    Component(Entity* entity) : entity(entity) {}
    virtual ~Component() = default;

    virtual void Awake() {}
    virtual void Start() {}
    virtual void Update(float deltaTime) {}
};