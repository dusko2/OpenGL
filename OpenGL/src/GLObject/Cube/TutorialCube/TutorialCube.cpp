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
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f },

    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f },

    Archiv::Vertex {-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f },

    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f },

    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f },

    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f }
};

TutorialCube::TutorialCube() : camera(Camera::GetInstance()) {
    vertexArray = new VertexArray();

    VertexBuffer vertexBuffer(tutorialCubeVertices, sizeof(tutorialCubeVertices) / sizeof(Archiv::Vertex));

    VertexBufferLayout vertexBufferLayout;
    vertexBufferLayout.Add<float>(3); // positions
    vertexBufferLayout.Add<float>(3); // normals

    vertexArray->AddBuffer(vertexBuffer, vertexBufferLayout);

    shaderProgram = new ShaderProgram();
    shaderProgram->AddShader(new Shader(GL_VERTEX_SHADER, "TutorialCube.vs"));
    shaderProgram->AddShader(new Shader(GL_FRAGMENT_SHADER, "TutorialCube.fs"));
    shaderProgram->Finalize();

    shaderProgram->Bind();

    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    shaderProgram->SetUniformVec3("u_lightColor", lightColor);

    glm::vec3 lightPosition = glm::vec3(1.2f, 1.0f, 2.0f);
    shaderProgram->SetUniformVec3("u_lightPosition", lightPosition);

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
