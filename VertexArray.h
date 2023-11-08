#pragma once

#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

class VertexArray
{
public:
    unsigned int id;

    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
};