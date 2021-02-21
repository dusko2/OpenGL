#include "GLFWController/GLFWController.h"
#include "Window/Window.h"
#include "GLADController/GLADController.h"
#include "GLObject/ShaderLoader/ShaderLoader.h"

int main(void) {
    // Setup GLFW and create window
    GLFWController::GetInstance().Initialize();
    if (Window* window = GLFWController::GetInstance().CreateWindow(1280, 720, "Dusko Car")) {
        // Initialize OpenGL AFTER creating window context
        GLADController::GetInstance().Initialize();

        ShaderLoader::GetInstance().Load();

        window->Initialize();
        window->Show();

        delete window;
    }

    GLFWController::GetInstance().Terminate();
    return 0;
}
