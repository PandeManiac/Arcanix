#include "Window.h"

#include "Input.h"
#include <iostream>

glm::ivec2 Window::Size;
std::string Window::Title;

float Window::AspectRatio;

GLFWwindow* Window::GameWindow;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

Window::Window(glm::ivec2 size, std::string title, GLFWmonitor* monitor, GLFWwindow* share)
{
	AspectRatio = (float)size.x / (float)size.y;

	if (!glfwInit())
	{
		std::cout << "GLFW Failed to Initialize!" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GameWindow = glfwCreateWindow(size.x, size.y, title.c_str(), monitor, share);

	glfwSwapInterval(0);
	glfwMakeContextCurrent(GameWindow);

	if (!gladLoadGL())
	{
		std::cout << "GLAD Initialization Failed!" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, size.x, size.y);

	glfwSetFramebufferSizeCallback(GameWindow, framebuffer_size_callback);
	glfwSetCursorPosCallback(GameWindow, mouse_callback);
}

Window::~Window()
{
	Terminate();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Window::Size = glm::ivec2(width, height);
	Window::AspectRatio = (float)Window::Size.x / (float)Window::Size.y;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	Input::UpdateMousePosition(static_cast<float>(xpos), static_cast<float>(ypos));
}