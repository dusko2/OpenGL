#pragma once

#include "../../../Math/Math.h"

class Camera;
class ShaderProgram;
class VertexArray;
class Texture2D;

class TutorialCube {

    private:
        Camera& camera;

        ShaderProgram* shaderProgram;
        VertexArray* vertexArray;

        Texture2D* containerTexture;
        Texture2D* smileTexture;

        glm::vec3* position;

    public:
        TutorialCube();
        ~TutorialCube();

        void Bind();
        void Unbind();

        inline const glm::vec3& GetPosition() const {
            return *position;
        }

        inline void SetPosition(float x, float y, float z) {
            position->x = x;
            position->y = y;
            position->z = z;
        }
};

