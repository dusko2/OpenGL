#pragma once

#include "../GLObject.h"

class Texture2D : public GLObject {

    private:
        uint32 index;

    public:
        Texture2D(const char* filepath, bool transparent, uint32 index);
        ~Texture2D();

        void Bind() const;
        void Unbind() const;
};
