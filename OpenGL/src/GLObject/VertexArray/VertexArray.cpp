#include <glad/glad.h>

#include "../VertexBuffer/VertexBuffer.h"
#include "../VertexBufferLayout/VertexBufferLayout.h"
#include "../GLUtils.h"
#include "VertexArray.h"

VertexArray::VertexArray() : GLObject(__func__) {
    GLCall(glGenVertexArrays(1, &rendererID));
    GLCall(glBindVertexArray(rendererID));
}

VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1, &rendererID));
}

void VertexArray::Bind() const {
    GLCall(glBindVertexArray(rendererID));
}

void VertexArray::Unbind() const {
    GLCall(glBindVertexArray(0));
}

void VertexArray::AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout) {
    buffer.Bind();

    const auto& elements = layout.GetElements();
    uint64 offset = 0;

    for (int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];

        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (void*)offset));

        offset += element.count * sizeof(float);
    }
}
