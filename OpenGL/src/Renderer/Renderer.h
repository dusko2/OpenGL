#pragma once

#include "../Math/Math.h"

class VertexArray;
class ShaderProgram;
class IndexBuffer;
class Texture2D;
class Camera;

namespace Archiv {

    class Quad;
    class Cube;
}

class Renderer {

    private:
        Camera& camera;

    public:
        Renderer();

        void Clear() const;

        void Draw(const VertexArray& vertexArray, ShaderProgram& shaderProgram, const glm::mat4& model, const Texture2D& texture) const;

        void Draw(const VertexArray& vertexArray,
                  const IndexBuffer& indexBuffer,
                  ShaderProgram& shaderProgram,
                  const glm::mat4& model,
                  const Texture2D& texture) const;

        void Draw(Archiv::Quad& quad, const glm::mat4& model);
        void Draw(Archiv::Cube& cube);
};
