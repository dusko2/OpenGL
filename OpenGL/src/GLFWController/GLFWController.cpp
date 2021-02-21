#include <iostream>
#include <GLFW/glfw3.h>

#include "../Window/Window.h"
#include "GLFWController.h"

GLFWController::GLFWController() {}

GLFWController::~GLFWController() {}

void GLFWController::Initialize() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void GLFWController::Terminate() {
    glfwTerminate();
}

Window* GLFWController::CreateWindow(uint32 width, uint32 height, const char* title) {
    if (GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL)) {
        glfwMakeContextCurrent(window);

        return new Window(window, width, height, title);
    }

    std::cout << ">> [OpenGL] Failed to create window" << std::endl;
    Terminate();

    return nullptr;
}
