#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "UIWindow.h"
#include "../GLObject/Shader/Shader.h"
#include "../GLObject/ShaderProgram/ShaderProgram.h"
#include "../GLObject/VertexBuffer/VertexBuffer.h"
#include "../GLObject/IndexBuffer/IndexBuffer.h"
#include "../GLObject/VertexArray/VertexArray.h"
#include "../GLObject/VertexBufferLayout/VertexBufferLayout.h"
#include "../Renderer/Renderer.h"
#include "../GLObject/GLUtils.h"
#include "../GLObject/Texture/Texture2D.h"
#include "../GLObject/Mouse/Mouse.h"
#include "../GLObject/Camera/Camera.h"

Camera& camera = Camera::GetInstance();

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

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
    Mouse::GetInstance().Update((float)positionX, (float)positionY);
    camera.Look();
}

UIWindow::UIWindow(const char* title, int width, int height)
    : title(title), width(width), height(height), internalWindow(nullptr) {}

UIWindow::~UIWindow() {}

void UIWindow::Initialize() {
    internalWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    if (internalWindow == nullptr) {
        std::cout << ">> [OpenGL] Failed to create window" << std::endl;
        glfwTerminate();
    } else {
        glfwMakeContextCurrent(internalWindow);
        glfwSwapInterval(0);
    }
}

void UIWindow::OnGladInit() {
    static int onGladInitCounter = 0;
    onGladInitCounter++;

    if (onGladInitCounter > 1) {
        std::cout << ">> [OpenGL] OnGladInit called more than once" << std::endl;
        return;
    }

    GLCall(glViewport(0, 0, width, height));
    glfwSetFramebufferSizeCallback(internalWindow, FrameBufferSizeCallback);
    glfwSetInputMode(internalWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(internalWindow, MouseCallback);
}

void UIWindow::StartLoop() {
    {
        glm::mat4 projection = glm::perspective(glm::radians(44.0f), 1280.0f / 720.0f, 0.1f, 100.0f);

        float vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
             0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
             0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
             0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
             0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
        };

        VertexArray vertexArray;

        VertexBuffer vertexBuffer(vertices, sizeof(vertices));
        VertexBufferLayout vertexBufferLayout;

        vertexBufferLayout.Add<float>(3);
        vertexBufferLayout.Add<float>(2);

        vertexArray.AddBuffer(vertexBuffer, vertexBufferLayout);

        ShaderProgram shaderProgram;
        shaderProgram.AddShader(new Shader(GL_VERTEX_SHADER, "VertexShader"));
        shaderProgram.AddShader(new Shader(GL_FRAGMENT_SHADER, "FragmentShader"));
        shaderProgram.Finalize();

        Texture2D containerTexture("res/textures/container.jpg", false, 0);
        Texture2D smileTexture("res/textures/awesomeface.png", true, 1);

        shaderProgram.Bind();
        shaderProgram.SetUniform1i("u_texture_1", 0);
        shaderProgram.SetUniform1i("u_texture_2", 1);
        shaderProgram.SetUniformMatrix4f("u_projection", projection);

        vertexBuffer.Unbind();
        vertexArray.Unbind();
        shaderProgram.Unbind();
        containerTexture.Unbind();
        smileTexture.Unbind();

        Renderer renderer;

        glm::vec3 cubePositions[] = {
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(0.0f, 0.0f, 2.0f),
            glm::vec3(0.0f, 0.0f, 3.0f),
            glm::vec3(0.0f, 0.0f, 4.0f),
            glm::vec3(0.0f, 0.0f, 5.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(2.0f, 0.0f, 0.0f),
            glm::vec3(3.0f, 0.0f, 0.0f),
            glm::vec3(4.0f, 0.0f, 0.0f)
        };

        //glfwSetCursorPos(internalWindow, lastX, lastY);
        while (!ShouldClose()) {
            float currentFrame = (float)glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            ProcessInput(internalWindow);

            renderer.Clear();

            containerTexture.Bind();
            smileTexture.Bind();

            shaderProgram.Bind();
            shaderProgram.SetUniformMatrix4f("u_view", camera.GetView());

            for (unsigned int i = 0; i < 10; i++) {
                glm::mat4 model = glm::translate(glm::mat4(1.0f), cubePositions[i]);

                model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.3f, 0.5f));

                shaderProgram.SetUniformMatrix4f("u_model", model);

                renderer.Draw(vertexArray, shaderProgram);
            }

            renderer.Draw(vertexArray, shaderProgram);

            glfwSwapBuffers(internalWindow);
            glfwPollEvents();
        }
    }

    glfwTerminate();
}

bool UIWindow::ShouldClose() {
    return glfwWindowShouldClose(internalWindow);
}

/* static */ void UIWindow::FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    GLCall(glViewport(0, 0, width, height));
}
