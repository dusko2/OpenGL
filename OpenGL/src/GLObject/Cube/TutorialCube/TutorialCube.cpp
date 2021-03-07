#include <glad/glad.h>

#include "../../ShaderProgram/ShaderProgram.h"
#include "../../Shader/Shader.h"
#include "../../VertexBuffer/VertexBuffer.h"
#include "../../VertexArray/VertexArray.h"
#include "../../VertexBufferLayout/VertexBufferLayout.h"
#include "../../Camera/Camera.h"
#include "../../Vertex/Vertex.h"
#include "../../Texture/Texture2D.h"
#include "TutorialCube.h"

Archiv::Vertex tutorialCubeVertices[] = {
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f },

    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f },

    Archiv::Vertex {-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f },

    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f },

    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f },

    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f }
};

TutorialCube::TutorialCube() : camera(Camera::GetInstance()) {
    vertexArray = new VertexArray();

    VertexBuffer vertexBuffer(tutorialCubeVertices, sizeof(tutorialCubeVertices) / sizeof(Archiv::Vertex));

    VertexBufferLayout vertexBufferLayout;
    vertexBufferLayout.Add<float>(3); // positions
    vertexBufferLayout.Add<float>(3); // normals
    vertexBufferLayout.Add<float>(2); // texture coords

    vertexArray->AddBuffer(vertexBuffer, vertexBufferLayout);

    shaderProgram = new ShaderProgram();
    shaderProgram->AddShader(new Shader(GL_VERTEX_SHADER, "TutorialCube.vs"));
    shaderProgram->AddShader(new Shader(GL_FRAGMENT_SHADER, "TutorialCube.fs"));
    shaderProgram->Finalize();

    texture = new Texture2D("res/textures/container2.png", true, 0);
    textureSpecular = new Texture2D("res/textures/container2_specular.png", true, 1);

    textureSpecular->Unbind();
    texture->Unbind();
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
