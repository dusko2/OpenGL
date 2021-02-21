#include <iostream>

#include <glad/glad.h>

#include "../Shader/Shader.h"
#include "../GLUtils.h"
#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() : GLObject(__func__) {
    GLCall(rendererID = glCreateProgram());
}

ShaderProgram::~ShaderProgram() {
    GLCall(glDeleteProgram(rendererID));
}

void ShaderProgram::AddShader(Shader* shader) {
    shaders.push_back(shader);
    GLCall(glAttachShader(rendererID, shader->GetRendererID()));
}

void ShaderProgram::Finalize() {
    if (!Link()) {
        PrintCompileError();
    }

    for (auto shader : shaders) {
        delete shader;
    }

    shaders.clear();
}

void ShaderProgram::Bind() const {
    GLCall(glUseProgram(rendererID));
}

void ShaderProgram::Unbind() const {
    GLCall(glUseProgram(0));
}

void ShaderProgram::SetUniform1f(const std::string& name, float value) {
    GLCall(glUniform1f(GetUniform(name), value));
}

void ShaderProgram::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4) {
    GLCall(glUniform4f(GetUniform(name), v1, v2, v3, v4));
}

void ShaderProgram::SetUniformMatrix4f(const std::string& name, glm::mat4 value) {
    GLCall(glUniformMatrix4fv(GetUniform(name), 1, GL_FALSE, glm::value_ptr(value)));
}

void ShaderProgram::SetUniform1i(const std::string& name, int value) {
    GLCall(glUniform1i(GetUniform(name), value));
}

bool ShaderProgram::Link() {
    GLCall(glLinkProgram(rendererID));

    int success;
    GLCall(glGetProgramiv(rendererID, GL_LINK_STATUS, &success));

    return success;
}

void ShaderProgram::PrintCompileError() {
    char infoLog[512];
    GLCall(glGetProgramInfoLog(rendererID, 512, NULL, infoLog));

    std::cout << ">> [OpenGL] Error linking shaders " << infoLog << std::endl;
}

const uint32 ShaderProgram::GetUniform(const std::string& name) {
    if (uniformLocations.find(name) != uniformLocations.end()) {
        return uniformLocations[name];
    }

    GLCall(uint32 location = glGetUniformLocation(rendererID, name.c_str()));

    if (location == -1) {
        std::cout << ">> [OpenGL] Warning: Uniform with name = " << name << " doesn't exist." << std::endl;
    } else {
        uniformLocations[name] = location;
    }

    return location;
}
