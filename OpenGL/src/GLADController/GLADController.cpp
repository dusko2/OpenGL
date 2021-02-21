#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLADController.h"

GLADController::GLADController() {}

GLADController::~GLADController() {}

void GLADController::Initialize() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << ">> [OpenGL] Failed to initialize GLAD" << std::endl;
        return;
    }

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(GLDebugCallback, nullptr);
}

void GLADController::LogError(const char* message) {
    std::cerr << ">> [ERROR]: " << message << std::endl;
}

void GLADController::LogInfo(const char* message) {
    std::cout << ">> [INFO]: " << message << std::endl;
}

void GLADController::GLDebugCallback(
    uint32 source,
    uint32 type,
    uint32 id,
    uint32 severity,
    int32 length,
    const char* message,
    const void* userParam
) {
    std::cout << "--------------------------------------------------------" << std::endl;

    std::cout << ">> [OpenGL] Source: "   << source   << std::endl;
    std::cout << ">> [OpenGL] Type: "     << type     << std::endl;
    std::cout << ">> [OpenGL] ID: "       << id       << std::endl;
    std::cout << ">> [OpenGL] Severity: " << severity << std::endl;
    std::cout << ">> [OpenGL] Length: "   << length   << std::endl;

    if (severity == GL_DEBUG_SEVERITY_NOTIFICATION) {
        LogInfo(message);
    } else {
        LogError(message);
        __debugbreak();
    }


    std::cout << "--------------------------------------------------------" << std::endl;
}
