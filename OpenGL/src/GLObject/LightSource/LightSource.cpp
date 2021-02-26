#include <glad/glad.h>

#include "../ShaderProgram/ShaderProgram.h"
#include "../Shader/Shader.h"
#include "../VertexBuffer/VertexBuffer.h"
#include "../VertexArray/VertexArray.h"
#include "../VertexBufferLayout/VertexBufferLayout.h"
#include "../Camera/Camera.h"
#include "../Vertex/Vertex.h"
#include "LightSource.h"

Archiv::Vertex lightSourceVertices[] = {
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

LightSource::LightSource() : camera(Camera::GetInstance()) {
    vertexArray = new VertexArray();

    VertexBuffer vertexBuffer(lightSourceVertices, sizeof(lightSourceVertices) / sizeof(Archiv::Vertex));

    VertexBufferLayout vertexBufferLayout;
    vertexBufferLayout.Add<float>(3);

    vertexArray->AddBuffer(vertexBuffer, vertexBufferLayout);

    shaderProgram = new ShaderProgram();
    shaderProgram->AddShader(new Shader(GL_VERTEX_SHADER, "LightSourceVertexShader"));
    shaderProgram->AddShader(new Shader(GL_FRAGMENT_SHADER, "LightSourceFragmentShader"));
    shaderProgram->Finalize();

    shaderProgram->Bind();

    vertexBuffer.Unbind();
    shaderProgram->Unbind();
    vertexArray->Unbind();

    position = new glm::vec3(0.0f, 0.0f, 0.0f);
}

LightSource::~LightSource() {
    delete shaderProgram;
    delete vertexArray;
    delete position;
}
