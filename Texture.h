#pragma once

#pragma warning(push, 0)
#include "src/vendor/STBI/stb_image.h"
#pragma warning(pop)

#include <string>

class Texture
{
private:
    std::string filePath;
    unsigned char* localBuffer;

    int width;
    int height;
    int bitsPerPixel;

public:
    unsigned int id;

    Texture(std::string filePath);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;
};