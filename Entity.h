#pragma once

#include "Component.h"
#include <vector>
#include <memory>
#include <string>
#include "Transform.h"

class Entity
{
private:
    std::string name;
    std::vector<std::unique_ptr<Component>> components;

public:
    Transform* transform = nullptr;

    Entity()
    {
        transform = AddComponent<Transform>();
    }

    template <typename T, typename... Args>
    T* AddComponent(Args&&... args)
    {
        T* newComponent = new T(this, std::forward<Args>(args)...);
        components.push_back(std::unique_ptr<Component>(newComponent));
        return newComponent;
    }

    template <typename T>
    T* GetComponent()
    {
        for (auto& component : components)
        {
            T* castedComponent = dynamic_cast<T*>(component.get());

            if (castedComponent)
            {
                return castedComponent;
            }
        }

        return nullptr;
    }
};