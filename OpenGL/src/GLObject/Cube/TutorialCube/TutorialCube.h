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
        Texture2D* texture;
        Texture2D* textureSpecular;

        glm::vec3* position;

    public:
        TutorialCube();
        ~TutorialCube();

        inline ShaderProgram& GetShaderProgram() const {
            return *shaderProgram;
        }

        inline const VertexArray& GetVertexArray() const {
            return *vertexArray;
        }

        inline const Texture2D& GetTexture() const {
            return *texture;
        }

        inline const Texture2D& GetTextureSpecular() const {
            return *textureSpecular;
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
