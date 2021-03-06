#include <glad/glad.h>

#include "../Vertex/Vertex.h"
#include "../ShaderProgram/ShaderProgram.h"
#include "../Shader/Shader.h"
#include "../VertexArray/VertexArray.h"
#include "../VertexBuffer/VertexBuffer.h"
#include "../VertexBufferLayout/VertexBufferLayout.h"
#include "../IndexBuffer/IndexBuffer.h"
#include "../Texture/Texture2D.h"

#include "Quad.h"

namespace Archiv {

    Quad::Quad(const Vertex* vertices, const std::string& textureFile, bool transparent) {
        shaderProgram = new ShaderProgram();
        shaderProgram->AddShader(new Shader(GL_VERTEX_SHADER, "CubeVertexShader"));
        shaderProgram->AddShader(new Shader(GL_FRAGMENT_SHADER, "CubeFragmentShader"));
        shaderProgram->Finalize();

        vertexArray = new VertexArray();

        VertexBuffer vertexBuffer(vertices, 6);
        VertexBufferLayout vertexBufferLayout;

        vertexBufferLayout.Add<float>(3); // Positions
        vertexBufferLayout.Add<float>(2); // Texture coordinates

        vertexArray->AddBuffer(vertexBuffer, vertexBufferLayout);

        texture = new Texture2D(textureFile.c_str(), transparent, 0);

        texture->Unbind();
        vertexBuffer.Unbind();
        vertexArray->Unbind();
        shaderProgram->Unbind();
    }

    Quad::~Quad() {
        delete texture;
        delete vertexArray;
        delete shaderProgram;
    }
}
