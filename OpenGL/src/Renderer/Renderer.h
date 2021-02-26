#pragma once

#include "../Math/Math.h"

class VertexArray;
class ShaderProgram;
class IndexBuffer;
class Cube;
class Camera;

class TutorialCube;

class Renderer {

    private:
        Camera& camera;

    public:
        Renderer();

        void Clear() const;

        void Draw(const VertexArray& vertexArray, ShaderProgram& shaderProgram, const glm::vec3& position) const;
        void Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, ShaderProgram& shaderProgram, const glm::vec3& position) const;

        void Draw(Cube& cube);
        void DrawTutorialCube(TutorialCube& cube);
        void DrawLightSource(LightSource& cube);
};
