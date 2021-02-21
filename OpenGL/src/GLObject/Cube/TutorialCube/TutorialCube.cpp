#include <glad/glad.h>

#include "../../ShaderProgram/ShaderProgram.h"
#include "../../Shader/Shader.h"
#include "../../VertexBuffer/VertexBuffer.h"
#include "../../VertexArray/VertexArray.h"
#include "../../VertexBufferLayout/VertexBufferLayout.h"
#include "../../Texture/Texture2D.h"
#include "../../Camera/Camera.h"
#include "../../Vertex/Vertex.h"
#include "TutorialCube.h"

Archiv::Vertex tutorialCubeVertices[] = {
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, 0.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, 0.0f },

    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f },

    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  1.0f, 0.0f },

    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f, 0.0f },

    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  1.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, 1.0f },

    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  0.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f }
};

TutorialCube::TutorialCube() : camera(Camera::GetInstance()) {
    vertexArray = new VertexArray();

    VertexBuffer vertexBuffer(tutorialCubeVertices, sizeof(tutorialCubeVertices));
    VertexBufferLayout vertexBufferLayout;

    vertexBufferLayout.Add<float>(3);
    vertexBufferLayout.Add<float>(2);

    vertexArray->AddBuffer(vertexBuffer, vertexBufferLayout);

    shaderProgram = new ShaderProgram();
    shaderProgram->AddShader(new Shader(GL_VERTEX_SHADER, "TutorialCubeVertexShader"));
    shaderProgram->AddShader(new Shader(GL_FRAGMENT_SHADER, "TutorialCubeFragmentShader"));
    shaderProgram->Finalize();

    containerTexture = new Texture2D("res/textures/container.jpg", false, 0);
    smileTexture = new Texture2D("res/textures/awesomeface.png", true, 1);

    shaderProgram->Bind();
    shaderProgram->SetUniform1i("u_texture_1", 0);
    shaderProgram->SetUniform1i("u_texture_2", 1);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
    shaderProgram->SetUniformMatrix4f("u_projection", projection);

    containerTexture->Unbind();
    smileTexture->Unbind();
    vertexBuffer.Unbind();
    shaderProgram->Unbind();
    vertexArray->Unbind();

    position = new glm::vec3(0.0f, 0.0f, 0.0f);
}

TutorialCube::~TutorialCube() {
    delete containerTexture;
    delete smileTexture;
    delete shaderProgram;
    delete vertexArray;
}

void TutorialCube::Bind() {
    shaderProgram->Bind();

    glm::mat4 model = glm::translate(glm::mat4(1.0f), *position);
    shaderProgram->SetUniformMatrix4f("u_model", model);
    shaderProgram->SetUniformMatrix4f("u_view", camera.GetView());

    vertexArray->Bind();
    containerTexture->Bind();
    smileTexture->Bind();
}

void TutorialCube::Unbind() {
    containerTexture->Unbind();
    smileTexture->Unbind();
    shaderProgram->Unbind();
    vertexArray->Unbind();
}
