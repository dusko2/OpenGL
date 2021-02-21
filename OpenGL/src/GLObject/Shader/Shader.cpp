#include <iostream>

#include <glad/glad.h>

#include "../GLUtils.h"
#include "../ShaderLoader/ShaderLoader.h"
#include "Shader.h"

Shader::Shader(uint32 type, const char* name) : GLObject(__func__) {
    GLCall(rendererID = glCreateShader(type));

    const char* source = ShaderLoader::GetInstance().GetSource(name);
    GLCall(glShaderSource(rendererID, 1, &source, NULL));

    if (!Compile()) {
        PrintCompileError();
    }
}

Shader::~Shader() {
    GLCall(glDeleteShader(rendererID));
}

bool Shader::Compile() {
    GLCall(glCompileShader(rendererID));

    int success;
    GLCall(glGetShaderiv(rendererID, GL_COMPILE_STATUS, &success));

    return success;
}

void Shader::PrintCompileError() {
    char error[512];
    GLCall(glGetShaderInfoLog(rendererID, 512, nullptr, error));

    std::cout << ">> [OpenGL] Error compiling shader\n" << error << std::endl;
}
