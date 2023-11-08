#include "VertexArray.h"

#include <glad/glad.h>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &id);
    Bind();
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &id);
}

void VertexArray::Bind() const
{
    glBindVertexArray(id);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}


void VertexArray::AddBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout)
{
    vbo.Bind();
    unsigned int offset = 0;

    const auto& elements = layout.GetElements();

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];

        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
        glEnableVertexAttribArray(i);

        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}