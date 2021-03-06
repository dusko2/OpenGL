#include <glad/glad.h>

#include "../ShaderProgram/ShaderProgram.h"
#include "../Shader/Shader.h"
#include "../VertexArray/VertexArray.h"
#include "../VertexBuffer/VertexBuffer.h"
#include "../VertexBufferLayout/VertexBufferLayout.h"
#include "../Texture/Texture2D.h"
#include "../Vertex/Vertex.h"

#include "Cube.h"

Archiv::Vertex backSide[] = {
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, /* 0.0f, 0.0f */ },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, /* 0.0f, 0.0f */ }
};

Archiv::Vertex frontSide[] = {
    Archiv::Vertex {-0.5f, -0.5f,  0.5f, /* 0.0f, 0.0f */ },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f, /* 0.0f, 0.0f */ }
};

Archiv::Vertex leftSide[] = {
    Archiv::Vertex {-0.5f,  0.5f,  0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f, /* 0.0f, 0.0f */ },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f, /* 1.0f, 0.0f */ }
};

Archiv::Vertex rightSide[] = {
    Archiv::Vertex { 0.5f,  0.5f,  0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f, /* 0.0f, 0.0f */ },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f, /* 1.0f, 0.0f */ }
};

Archiv::Vertex bottomSide[] = {
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex { 0.5f, -0.5f, -0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex { 0.5f, -0.5f,  0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex {-0.5f, -0.5f,  0.5f, /* 0.0f, 0.0f */ },
    Archiv::Vertex {-0.5f, -0.5f, -0.5f, /* 0.0f, 1.0f */ }
};

Archiv::Vertex topSide[] = {
    Archiv::Vertex {-0.5f,  0.5f, -0.5f, /* 0.0f, 1.0f */ },
    Archiv::Vertex { 0.5f,  0.5f, -0.5f, /* 1.0f, 1.0f */ },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex { 0.5f,  0.5f,  0.5f, /* 1.0f, 0.0f */ },
    Archiv::Vertex {-0.5f,  0.5f,  0.5f, /* 0.0f, 0.0f */ },
    Archiv::Vertex {-0.5f,  0.5f, -0.5f, /* 0.0f, 1.0f */ }
};

Cube::Cube() {
    shaderProgram = new ShaderProgram();
    shaderProgram->AddShader(new Shader(GL_VERTEX_SHADER, "CubeVertexShader"));
    shaderProgram->AddShader(new Shader(GL_FRAGMENT_SHADER, "CubeFragmentShader"));
    shaderProgram->Finalize();

    vertexArray = new VertexArray();

    VertexBuffer vertexBuffer(nullptr, sizeof(float));
    VertexBufferLayout vertexBufferLayout;

    vertexBufferLayout.Add<float>(3); // Positions
    vertexBufferLayout.Add<float>(2); // Texture coordinates

    vertexArray->AddBuffer(vertexBuffer, vertexBufferLayout);

    texture = new Texture2D("res/textures/container.jpg", false, 0);

    texture->Unbind();
    vertexBuffer.Unbind();
    vertexArray->Unbind();
    shaderProgram->Unbind();

    position = new glm::vec3(0.0f, 0.0f, 0.0f);
}

Cube::~Cube() {
    delete texture;
    delete vertexArray;
    delete shaderProgram;

    delete position;
}

void Cube::OnBeforeRender() {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), *position);
    shaderProgram->SetUniformMatrix4f("u_model", model);


    texture->Bind();
}
