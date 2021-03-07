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
#include "../GLObject/Cube/TutorialCube/TutorialCube.h"
#include "../GLObject/LightSource/LightSource.h"
#include "../GLObject/Camera/Camera.h"

#include "Renderer.h"

Renderer::Renderer() : camera(Camera::GetInstance()) {
    GLCall(glEnable(GL_DEPTH_TEST));
}

void Renderer::Clear() const {
    GLCall(glClearColor(0.1f, 0.3f, 0.5f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& vertexArray, ShaderProgram& shaderProgram, const glm::vec3& position) const {
    shaderProgram.Bind();
    shaderProgram.SetUniformMatrix4f("u_model", glm::translate(glm::mat4(1.0f), position));
    shaderProgram.SetUniformMatrix4f("u_view", camera.GetView());
    shaderProgram.SetUniformMatrix4f("u_projection", camera.GetProjection());

    vertexArray.Bind();

    GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
}

void Renderer::Draw(const VertexArray& vertexArray,
                    const IndexBuffer& indexBuffer,
                    ShaderProgram& shaderProgram,
                    const glm::vec3& position) const {

    shaderProgram.Bind();
    shaderProgram.SetUniformMatrix4f("u_model", glm::translate(glm::mat4(1.0f), position));
    shaderProgram.SetUniformMatrix4f("u_view", camera.GetView());
    shaderProgram.SetUniformMatrix4f("u_projection", camera.GetProjection());

    vertexArray.Bind();
    indexBuffer.Bind();

    GLCall(glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(Cube& cube) {
    cube.OnBeforeRender();

    Draw(cube.GetVertexArray(), cube.GetShaderProgram(), cube.GetPosition());
}

void Renderer::DrawTutorialCube(TutorialCube& cube, float diff) {
    ShaderProgram& shaderProgram = cube.GetShaderProgram();
    const glm::vec3& position = cube.GetPosition();

    shaderProgram.Bind();

    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    // model = glm::rotate(model, glm::radians(diff * 25.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shaderProgram.SetUniformMatrix4f("u_model", model);

    shaderProgram.SetUniformMatrix4f("u_view", camera.GetView());
    shaderProgram.SetUniformMatrix4f("u_projection", camera.GetProjection());
    shaderProgram.SetUniformVec3("u_cameraPosition", camera.GetPosition());

    shaderProgram.SetUniform1i("material.diffuse", 0);
    shaderProgram.SetUniform1i("material.specular", 1);
    shaderProgram.SetUniform1f("material.shininess", 32.0f);

    shaderProgram.SetUniformVec3("light.ambient", glm::vec3(0.2f, 0.2f, 0.2f));
    shaderProgram.SetUniformVec3("light.diffuse", glm::vec3(0.5f, 0.5f, 0.5f));
    shaderProgram.SetUniformVec3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));

    cube.GetVertexArray().Bind();
    cube.GetTexture().Bind();
    cube.GetTextureSpecular().Bind();

    GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
}

void Renderer::DrawLightSource(LightSource& cube, float diff) {
    const VertexArray& vertexArray = cube.GetVertexArray();
    ShaderProgram& shaderProgram = cube.GetShaderProgram();
    const glm::vec3& position = cube.GetPosition();

    shaderProgram.Bind();

    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    shaderProgram.SetUniformMatrix4f("u_model", glm::scale(model, glm::vec3(0.2f)));

    shaderProgram.SetUniformMatrix4f("u_view", camera.GetView());
    shaderProgram.SetUniformMatrix4f("u_projection", camera.GetProjection());

    vertexArray.Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
}
