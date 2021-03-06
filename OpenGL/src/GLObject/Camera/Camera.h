#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum class CameraDirection {

    Up    = 0,
    Down  = 1,
    Left  = 2,
    Right = 3,
    Front = 4,
    Back  = 5
};

class Camera {

    public:
        static Camera& GetInstance() {
            static Camera instance;
            return instance;
        }

    private:
        const float velocity = 2.5f;
        const float sensitivity = 0.1f;

        glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
        glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

        float yaw = -90.0f;
        float pitch = 0.0f;

        glm::vec3 direction;

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);

    public:
        void Move(CameraDirection cameraDirection, float deltaTime);
        void UpdateDirection(float offsetX, float offsetY);

        inline glm::mat4 GetView() const {
            return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        }

        inline const glm::mat4& GetProjection() const {
            return projection;
        }
};
