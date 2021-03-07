#include <iostream>
#include <fstream>
#include <sstream>

#include <glad/glad.h>

#include "../GLUtils.h"
#include "Shader.h"

Shader::Shader(uint32 type, const std::string& name) : GLObject(__func__) {
    GLCall(rendererID = glCreateShader(type));

    std::string source = ReadSource(name);
    const char* sourcePtr = source.c_str();
    GLCall(glShaderSource(rendererID, 1, &sourcePtr, NULL));

    if (!Compile()) {
        PrintCompileError();
    }
}

Shader::~Shader() {
    GLCall(glDeleteShader(rendererID));
}

std::string Shader::ReadSource(const std::string& name) {
    std::fstream fileInput(Shader::GetShaderPath() + name);

    std::string line;
    std::stringstream sourceBuilder;

    while (getline(fileInput, line)) {
        sourceBuilder << line << "\n";
    }

    return sourceBuilder.str();
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
