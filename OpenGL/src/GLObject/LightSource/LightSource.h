#pragma once

#include "../../Math/Math.h"

class Camera;
class ShaderProgram;
class VertexArray;

class LightSource {

    private:
        Camera& camera;

        ShaderProgram* shaderProgram;
        VertexArray* vertexArray;

        glm::vec3* position;

    public:
        LightSource();
        ~LightSource();

        inline ShaderProgram& GetShaderProgram() const {
            return *shaderProgram;
        }

        inline const VertexArray& GetVertexArray() const {
            return *vertexArray;
        }

        inline const glm::vec3& GetPosition() const {
            return *position;
        }

        inline void SetPosition(float x, float y, float z) {
            position->x = x;
            position->y = y;
            position->z = z;
        }
};
