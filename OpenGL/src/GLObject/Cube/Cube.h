#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram;
class VertexArray;
class Texture2D;

class Cube {

    private:
        ShaderProgram* shaderProgram;
        VertexArray* vertexArray;
        Texture2D* texture;

        glm::vec3* position;

    public:
        Cube();
        ~Cube();

        void OnBeforeRender();

        inline const ShaderProgram& GetShaderProgram() const {
            return *shaderProgram;
        }

        inline const VertexArray& GetVertexArray() const {
            return *vertexArray;
        }

        inline const Texture2D& GetTexture() const {
            return *texture;
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
