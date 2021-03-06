#include <glad/glad.h>

#include "../../ShaderProgram/ShaderProgram.h"
#include "../../Shader/Shader.h"
#include "../../VertexBuffer/VertexBuffer.h"
#include "../../VertexArray/VertexArray.h"
#include "../../VertexBufferLayout/VertexBufferLayout.h"
#include "../../Camera/Camera.h"
#include "../../Vertex/Vertex.h"
#include "TutorialCube.h"

Archiv::Vertex tutorialCubeVertices[] = {
    // Back side
    Archiv::Vertex {-0.5f, -0.5f, -0.5f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f },

    // Front side
    Archiv::Vertex {-0.5f, -0.5f,  0.5f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f },

    // Left side
    Archiv::Vertex {-0.5f,  0.5f,  0.5f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f },

    // Right side
    Archiv::Vertex { 0.5f,  0.5f,  0.5f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f },

    // Bottom side
    Archiv::Vertex {-0.5f, -0.5f, -0.5f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f },

    // Top side
    Archiv::Vertex {-0.5f,  0.5f, -0.5f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f }
};

TutorialCube::TutorialCube() : camera(Camera::GetInstance()) {
    vertexArray = new VertexArray();

    VertexBuffer vertexBuffer(tutorialCubeVertices, sizeof(tutorialCubeVertices) / sizeof(Archiv::Vertex));

    VertexBufferLayout vertexBufferLayout;
    vertexBufferLayout.Add<float>(3);

    vertexArray->AddBuffer(vertexBuffer, vertexBufferLayout);

    shaderProgram = new ShaderProgram();
    shaderProgram->AddShader(new Shader(GL_VERTEX_SHADER, "TutorialCubeVertexShader"));
    shaderProgram->AddShader(new Shader(GL_FRAGMENT_SHADER, "TutorialCubeFragmentShader"));
    shaderProgram->Finalize();

    shaderProgram->Bind();

    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    shaderProgram->SetUniformVec3("u_lightColor", lightColor);

    glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);
    shaderProgram->SetUniformVec3("u_objectColor", objectColor);

    vertexBuffer.Unbind();
    shaderProgram->Unbind();
    vertexArray->Unbind();

    position = new glm::vec3(0.0f, 0.0f, 0.0f);
}

TutorialCube::~TutorialCube() {
    delete shaderProgram;
    delete vertexArray;
    delete position;
}
