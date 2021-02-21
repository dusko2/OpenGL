#include <GLFW/glfw3.h>

#include "Mouse.h"

Mouse::Mouse() {}

void Mouse::Update(float positionX, float positionY) {
    offsetX = positionX - lastX;
    offsetY = lastY - positionY; // reversed since y-coordinates range from bottom to top

    lastX = positionX;
    lastY = positionY;
}

void Mouse::SetPosition(float x, float y) {
    lastX = x;
    lastY = y;

    offsetX = 0.0f;
    offsetY = 0.0f;

    glfwSetCursorPos(glfwGetCurrentContext(), lastX, lastY);
}
