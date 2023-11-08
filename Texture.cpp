#include "Texture.h"

#include <glad/glad.h>
#include <iostream>

Texture::Texture(std::string filePath) : filePath(filePath), localBuffer(nullptr), id(0), width(0), height(0), bitsPerPixel(0)
{
    stbi_set_flip_vertically_on_load(1);
    localBuffer = stbi_load(filePath.c_str(), &width, &height, &bitsPerPixel, 4);

    if (!localBuffer)
    {
        std::cout << "Failed to Load Texture from: \"" << filePath << "\"!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(localBuffer);
}

Texture::~Texture()
{
    glDeleteTextures(1, &id);
}

void Texture::Bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}