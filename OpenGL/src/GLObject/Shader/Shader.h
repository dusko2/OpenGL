#pragma once

#include "../GLObject.h"
#include "../../Utils/IntTypes.h"

class Shader : public GLObject {

    public:
        Shader(uint32 type, const char* source);
        ~Shader();

    private:
        bool Compile();
        void PrintCompileError();
};
