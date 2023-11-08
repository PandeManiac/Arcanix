#pragma once

#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <string>

class Window
{
public:
	static glm::ivec2 Size;
	static std::string Title;

	static float AspectRatio;

	static GLFWwindow* GameWindow;

	Window(glm::ivec2 size, std::string title, GLFWmonitor* monitor, GLFWwindow* share);
	~Window();

	bool ShouldClose() const
	{
		return glfwWindowShouldClose(GameWindow);
	}

	void SwapBuffers() const
	{
		glfwSwapBuffers(GameWindow);
	}

	void PollEvents() const
	{
		glfwPollEvents();
	}

	void ClearColor(float r, float g, float b, float a) const
	{
		glClearColor(r, g, b, a);
	}

	void Clear(int mask) const
	{
		glClear(mask);
	}

	void SetBackgroundColor(float r, float g, float b, float a) const
	{
		ClearColor(r, g, b, a);
		Clear(GL_COLOR_BUFFER_BIT);
	}

	void Terminate() const
	{
		glfwTerminate();
		std::exit(EXIT_SUCCESS);
	}
};