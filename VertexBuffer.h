#pragma once

class VertexBuffer
{
public:
	unsigned int id;

	VertexBuffer(const void* data, const unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};