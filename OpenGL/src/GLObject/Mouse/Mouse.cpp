#include <GLFW/glfw3.h>

#include "Mouse.h"

Mouse::Mouse() {
    glfwSetCursorPos(glfwGetCurrentContext(), lastX, lastY);
}

void Mouse::Update(float positionX, float positionY) {
    offsetX = positionX - lastX;
    offsetY = lastY - positionY; // reversed since y-coordinates range from bottom to top

    lastX = positionX;
    lastY = positionY;
}
