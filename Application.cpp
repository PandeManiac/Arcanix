#include "Window.h"
#include "Entity.h"
#include "PlayerMovement.h"
#include "PlayerLook.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Texture.h"
#include "Input.h"
#include "Time.h"

int main()
{
	glm::ivec2 windowSize(1920, 1080);
	std::string windowTitle("Arcanix Test");

	Window* window = new Window(windowSize, windowTitle, glfwGetPrimaryMonitor(), nullptr);

    Entity* player = new Entity();
	PlayerMovement* movement = player->AddComponent<PlayerMovement>(10.0f);
    Camera* camera = player->AddComponent<Camera>(70.0f, Window::AspectRatio, 0.1f, 100.0f);
    PlayerLook* look = player->AddComponent<PlayerLook>(1.0f);

    player->transform->Position.y = 2;

    Shader shader("assets/shaders/color/color.vertex", "assets/shaders/color/color.fragment");
    shader.Compile();
    shader.Link();

    float groundPlaneVertices[] =
    {
        -10.0f, 0.0f,  10.0f,   0.5f, 0.3f, 0.2f,
         10.0f, 0.0f, -10.0f,   0.5f, 0.3f, 0.2f,
        -10.0f, 0.0f, -10.0f,   0.5f, 0.3f, 0.2f,

        -10.0f, 0.0f,  10.0f,   0.5f, 0.3f, 0.2f,
         10.0f, 0.0f,  10.0f,   0.5f, 0.3f, 0.2f,
         10.0f, 0.0f, -10.0f,   0.5f, 0.3f, 0.2f,
    };

    VertexArray vao;
    VertexBuffer vbo(groundPlaneVertices, sizeof(groundPlaneVertices));

    vao.Bind();
    vbo.Bind();

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(3);

    vao.AddBuffer(vbo, layout);

    movement->Awake();
    look->Awake();

	while (!window->ShouldClose())
	{
		Input::Update();
		Time::Update();

        camera->CalculateViewMatrix();
        camera->CalculateProjectionMatrix();

        if (Input::GetKeyDown(Keys::Escape))
        {
            window->Terminate();
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.Use();
        shader.SetMatrix4f("model", glm::mat4(1.0f));
        shader.SetMatrix4f("projection", camera->Projection);
        shader.SetMatrix4f("view", camera->View);
        vao.Bind();

        glDrawArrays(GL_TRIANGLES, 0, 6);

        movement->Update(Time::GetDeltaTime());
        look->Update(Time::GetDeltaTime());

        window->SwapBuffers();
		window->PollEvents();
	}
}