#pragma once

#include "glad/glad.h"

class IndexBuffer
{
public:
    unsigned int id;
    unsigned int count;

    IndexBuffer(const unsigned int* data, const unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;
};