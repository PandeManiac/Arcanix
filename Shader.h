#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Shader
{
private:
	const char* vertexSource;
	const char* fragmentSource;

	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

public:
	Shader(std::string vertexShaderSource, std::string fragmentShaderSource);

	void Compile();
	void Link();

	void Use()
	{
		glUseProgram(shaderProgram);
	}

	void Delete()
	{
		glDeleteProgram(shaderProgram);
	}

	void SetBool(const std::string& name, bool value) const
	{
		glUniform1i(GetUniformLocation(name), (int)value);
	}

	void SetInt(const std::string& name, int value) const
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void SetFloat(const std::string& name, float value) const
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void SetMatrix4f(const std::string& name, glm::mat4 value)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

private:
	void CheckCompilationStatus(unsigned int toCheck, std::string type);

	std::string LoadShaderFromFile(const std::string& filePath)
	{
		std::ifstream file(filePath);

		if (!file.is_open())
		{
			std::cout << "Failed to Open File: \"" << filePath << "\" !" << std::endl;
			return "";
		}

		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		return buffer.str();
	}

	int GetUniformLocation(const std::string& name) const
	{
		int location = glGetUniformLocation(shaderProgram, name.c_str());

		if (location == -1)
		{
			std::cout << "No uniform named " << name << " found!" << std::endl;
		}

		return location;
	}
};