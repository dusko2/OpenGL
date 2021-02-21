#pragma once

class VertexArray;
class ShaderProgram;
class IndexBuffer;
class Cube;

class Renderer {

	public:
		Renderer();

		void Clear() const;

		void Draw(const VertexArray& vertexArray, const ShaderProgram& shaderProgram) const;
		void Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shaderProgram) const;

		void Draw(Cube& cube);
};
