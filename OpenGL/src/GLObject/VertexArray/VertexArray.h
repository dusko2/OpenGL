#pragma once

#include "../GLObject.h"
#include <vector>

class VertexBuffer;
class VertexBufferLayout;

class VertexArray : public GLObject {

    private:
        std::vector<VertexBuffer*> buffers;

    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void Unbind() const;

        void AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
};
