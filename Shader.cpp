#include "Shader.h"

Shader::Shader(std::string vertexShaderSource, std::string fragmentShaderSource) : vertexSource(""), fragmentSource(""), vertexShader(0), fragmentShader(0), shaderProgram(0)
{
    std::string tempVertexSource = LoadShaderFromFile(vertexShaderSource);
    std::string tempFragmentSource = LoadShaderFromFile(fragmentShaderSource);

    vertexSource = new char[tempVertexSource.length() + 1];
    strcpy_s(const_cast<char*>(vertexSource), tempVertexSource.length() + 1, tempVertexSource.c_str());

    fragmentSource = new char[tempFragmentSource.length() + 1];
    strcpy_s(const_cast<char*>(fragmentSource), tempFragmentSource.length() + 1, tempFragmentSource.c_str());
}

void Shader::Compile()
{
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    CheckCompilationStatus(vertexShader, "VERTEX");

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    CheckCompilationStatus(fragmentShader, "FRAGMENT");
}

void Shader::Link()
{
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    CheckCompilationStatus(shaderProgram, "SHADER");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::CheckCompilationStatus(unsigned int toCheck, std::string type)
{
    int success;
    char infoLog[512];

    if (type != "PROGRAM")
    {
        glGetShaderiv(toCheck, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(toCheck, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED" << std::endl << infoLog << std::endl;
        }

        return;
    }

    glGetProgramiv(toCheck, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(toCheck, 1024, NULL, infoLog);
        std::cout << "ERROR::" << type << "PROGRAM::LINKING_FAILED" << std::endl << infoLog << std::endl;
    }

    return;
}