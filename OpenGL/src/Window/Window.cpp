#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"

#include "../GLObject/Cube/TutorialCube/TutorialCube.h"
#include "../GLObject/LightSource/LightSource.h"
#include "../Renderer/Renderer.h"
#include "../GLObject/GLUtils.h"
#include "../GLObject/Mouse/Mouse.h"
#include "../GLObject/Camera/Camera.h"

Camera& camera = Camera::GetInstance();
Mouse& mouse = Mouse::GetInstance();

double fpsLimit = 1.0 / 60.0; // Game logic update limit
double lastTime = 0.0;
double timer = 0.0;

double deltaTime = 0.0;
double currentTime = 0.0;

int frames = 0;
int updates = 0;

inline double CurrentTime() {
    return glfwGetTime();
}

void ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.Move(CameraDirection::Front, (float)fpsLimit);
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.Move(CameraDirection::Back, (float)fpsLimit);
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.Move(CameraDirection::Left, (float)fpsLimit);
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.Move(CameraDirection::Right, (float)fpsLimit);
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        camera.Move(CameraDirection::Up, (float)fpsLimit);
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        camera.Move(CameraDirection::Down, (float)fpsLimit);
    }
}

void MouseCallback(GLFWwindow* window, double positionX, double positionY) {
    mouse.Update((float)positionX, (float)positionY);
    camera.UpdateDirection(mouse.GetOffsetX(), mouse.GetOffsetY());
}

Window::Window(GLFWwindow* context, uint32 width, uint32 height, const char* title)
    : context(context), width((float)width), height((float)height), title(title) {
}

Window::~Window() {}

void Window::Initialize() {
    GLCall(glViewport(0, 0, (int)width, (int)height));

    glfwSetFramebufferSizeCallback(context, FrameBufferSizeCallback);
    glfwSetInputMode(context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    mouse.SetPosition(width / 2.0f, height / 2.0f);

    glfwSetCursorPosCallback(context, MouseCallback);
    glfwSwapInterval(0);
}

void Window::Show() {
    Renderer renderer;

    TutorialCube cube;
    cube.SetPosition(0.0f, 0.0f, 0.0f);

    LightSource lightSource;
    lightSource.SetPosition(1.2f, 1.0f, 2.0f);

    while (!ShouldClose()) {
        currentTime = CurrentTime();
        deltaTime += (currentTime - lastTime) / fpsLimit;
        lastTime = currentTime;

        while (deltaTime >= 1.0) {
            ProcessInput(context);
            updates++;
            deltaTime--;
        }

        renderer.Clear();

        renderer.DrawTutorialCube(cube);
        renderer.DrawLightSource(lightSource);

        frames++;

        glfwSwapBuffers(context);
        glfwPollEvents();

        if (CurrentTime() - timer > 1.0) {
            timer++;

            std::cout << ">> [FPS] Current FPS = " << frames << ", and updates = " << updates << std::endl;

            frames = 0;
            updates = 0;
        }
    }
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(context);
}

/* static */ void Window::FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    GLCall(glViewport(0, 0, width, height));
}
