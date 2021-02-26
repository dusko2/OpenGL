#pragma once

#include "../GLObject.h"

class VertexBufferLayout;

namespace Archiv {

    struct Vertex;
}

class VertexBuffer : public GLObject {

    private:
        const uint32 count;

    public:
        VertexBuffer(const Archiv::Vertex* data, uint32 count);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

        inline const uint32& GetCount() const {
            return count;
        }
};
