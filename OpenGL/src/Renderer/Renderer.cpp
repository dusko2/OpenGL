#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../GLObject/VertexArray/VertexArray.h"
#include "../GLObject/IndexBuffer/IndexBuffer.h"
#include "../GLObject/ShaderProgram/ShaderProgram.h"
#include "../GLObject/GLUtils.h"

#include "../GLObject/Cube/Cube.h"
#include "../GLObject/Cube/TutorialCube/TutorialCube.h"

#include "Renderer.h"

Renderer::Renderer() {
    GLCall(glEnable(GL_DEPTH_TEST));
}

void Renderer::Clear() const {
    GLCall(glClearColor(0.1f, 0.3f, 0.5f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& vertexArray, const ShaderProgram& shaderProgram) const {
    shaderProgram.Bind();
    vertexArray.Bind();

    GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
}

void Renderer::Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shaderProgram) const {
    shaderProgram.Bind();
    vertexArray.Bind();
    indexBuffer.Bind();

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(Cube& cube) {
    cube.OnBeforeRender();

    Draw(cube.GetVertexArray(), cube.GetShaderProgram());
}

void Renderer::DrawTutorialCube(TutorialCube& cube) {
    cube.Bind();
    
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
}
