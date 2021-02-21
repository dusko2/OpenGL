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
#include "../Renderer/Renderer.h"
#include "../GLObject/GLUtils.h"
#include "../GLObject/Mouse/Mouse.h"
#include "../GLObject/Camera/Camera.h"

Camera& camera = Camera::GetInstance();
Mouse& mouse = Mouse::GetInstance();

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.Move(CameraDirection::Front, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.Move(CameraDirection::Back, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.Move(CameraDirection::Left, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.Move(CameraDirection::Right, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        camera.Move(CameraDirection::Up, deltaTime);
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        camera.Move(CameraDirection::Down, deltaTime);
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

    while (!ShouldClose()) {
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        ProcessInput(context);

        renderer.Clear();

        for (float x = 0.0f; x < 16.0f; x++) {
            for (float z = 0.0f; z < 16.0f; z++) {
                cube.SetPosition(x, 0.0f, z);
                renderer.DrawTutorialCube(cube);
            }
        }

        glfwSwapBuffers(context);
        glfwPollEvents();
    }
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(context);
}

/* static */ void Window::FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    GLCall(glViewport(0, 0, width, height));
}
