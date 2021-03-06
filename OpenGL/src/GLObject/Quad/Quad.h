#pragma once

#include <string>

class ShaderProgram;
class VertexArray;
class Texture2D;

namespace Archiv {

    struct Vertex;

    class Quad {

        private:
            ShaderProgram* shaderProgram;
            VertexArray* vertexArray;
            Texture2D* texture;

        public:
            Quad(const Vertex* vertices, const std::string& textureFile, bool transparent);
            ~Quad();

            inline ShaderProgram& GetShaderProgram() const {
                return *shaderProgram;
            }

            inline const VertexArray& GetVertexArray() const {
                return *vertexArray;
            }

            inline const Texture2D& GetTexture() const {
                return *texture;
            }
    };
}
