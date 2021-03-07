#pragma once

#include "../GLObject.h"
#include "../../Utils/IntTypes.h"

class Shader : public GLObject {

    public:
        static std::string& GetShaderPath() {
            static std::string shaderPath = "res/shaders/";
            return shaderPath;
        }

    public:
        Shader(uint32 type, const std::string& name);
        ~Shader();

    private:
        std::string ReadSource(const std::string& name);
        bool Compile();
        void PrintCompileError();
};
