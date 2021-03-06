#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../GLObject/VertexArray/VertexArray.h"
#include "../GLObject/VertexBuffer/VertexBuffer.h"
#include "../GLObject/IndexBuffer/IndexBuffer.h"
#include "../GLObject/ShaderProgram/ShaderProgram.h"
#include "../GLObject/Texture/Texture2D.h"
#include "../GLObject/GLUtils.h"

#include "../GLObject/Cube/Cube.h"
#include "../GLObject/Quad/Quad.h"
#include "../GLObject/Camera/Camera.h"

#include "Renderer.h"

Renderer::Renderer() : camera(Camera::GetInstance()) {
    GLCall(glEnable(GL_DEPTH_TEST));
}

void Renderer::Clear() const {
    GLCall(glClearColor(0.1f, 0.3f, 0.5f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& vertexArray,
                    ShaderProgram& shaderProgram,
                    const glm::mat4& model,
                    const Texture2D& texture) const {

    shaderProgram.Bind();
    shaderProgram.SetUniformMatrix4f("u_model", model);
    shaderProgram.SetUniformMatrix4f("u_view", camera.GetView());
    shaderProgram.SetUniformMatrix4f("u_projection", camera.GetProjection());

    vertexArray.Bind();
    texture.Bind();

    GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
}

void Renderer::Draw(const VertexArray& vertexArray,
                    const IndexBuffer& indexBuffer,
                    ShaderProgram& shaderProgram,
                    const glm::mat4& model,
                    const Texture2D& texture) const {

    shaderProgram.Bind();
    shaderProgram.SetUniformMatrix4f("u_model", model);
    shaderProgram.SetUniformMatrix4f("u_view", camera.GetView());
    shaderProgram.SetUniformMatrix4f("u_projection", camera.GetProjection());

    vertexArray.Bind();
    indexBuffer.Bind();
    texture.Bind();

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(Archiv::Quad& quad, const glm::mat4& model) {
    Draw(quad.GetVertexArray(), quad.GetShaderProgram(), model, quad.GetTexture());
}

void Renderer::Draw(Archiv::Cube& cube) {
    glm::mat4 model = cube.GetModel();
    for (auto& element : cube.GetSides()) {
        Draw(*element.second, model);
    }
}
