#pragma once

#include <vector>
#include <unordered_map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../GLObject.h"

class Shader;

class ShaderProgram : public GLObject {

    private:
        std::vector<Shader*> shaders;
        std::unordered_map<std::string, uint32> uniformLocations;

    public:
        ShaderProgram();
        ~ShaderProgram();

        void AddShader(Shader* shader);
        void Finalize();

        void Bind() const;
        void Unbind() const;

        void SetUniform1f(const std::string& name, float value);
        void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);

        void SetUniformMatrix4f(const std::string& name, glm::mat4 value);

        void SetUniform1i(const std::string& name, int value);

        void SetUniformVec3(const std::string& name, glm::vec3 value);

    private:
        bool Link();
        void PrintCompileError();

        const uint32 GetUniform(const std::string& name);
};
