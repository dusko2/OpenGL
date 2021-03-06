#pragma once

#include <string>

#include "../GLObject.h"

struct TextureInfo {

    const std::string& name;
    const std::string& type;
};

class Texture2D : public GLObject {

    private:
        uint32 index;

    public:
        Texture2D(const char* path, bool transparent, uint32 index);
        ~Texture2D();

        void Bind() const;
        void Unbind() const;
};
