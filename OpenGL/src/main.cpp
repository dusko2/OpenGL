#include "GLFWController/GLFWController.h"
#include "Window/Window.h"
#include "GLADController/GLADController.h"

int main(void) {
    // Setup GLFW and create window
    GLFWController::GetInstance().Initialize();
    if (Window* window = GLFWController::GetInstance().CreateWindow(1280, 720, "Dusko Car")) {
        // Initialize OpenGL AFTER creating window context
        GLADController::GetInstance().Initialize();

        window->Initialize();
        window->Show();

        delete window;
    }

    GLFWController::GetInstance().Terminate();
    return 0;
}
