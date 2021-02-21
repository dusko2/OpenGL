#include "../Mouse/Mouse.h"
#include "Camera.h"

void Camera::Move(CameraDirection cameraDirection, float deltaTime) {
    float speed = velocity * deltaTime;

    switch (cameraDirection) {
        case CameraDirection::Up:
            cameraPos += speed * cameraUp;
            break;
        case CameraDirection::Down:
            cameraPos -= speed * cameraUp;
            break;
        case CameraDirection::Left:
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
            break;
        case CameraDirection::Right:
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;
            break;
        case CameraDirection::Front:
            cameraPos += speed * cameraFront;
            break;
        case CameraDirection::Back:
            cameraPos -= speed * cameraFront;
            break;
    }
}

void Camera::UpdateDirection(float offsetX, float offsetY) {
    yaw += offsetX * sensitivity;
    pitch += offsetY * sensitivity;

    if (pitch > 89.0f) {
        pitch = 89.0f;
    }

    if (pitch < -89.0f) {
        pitch = -89.0f;
    }

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}
