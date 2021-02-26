#include <glad/glad.h>

#include "../GLUtils.h"
#include "VertexBuffer.h"
#include "../Vertex/Vertex.h"

#include <iostream>

VertexBuffer::VertexBuffer(const Archiv::Vertex* data, uint32 count) : GLObject(__func__), count(count) {
    GLCall(glGenBuffers(1, &rendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Archiv::Vertex) * count, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
    GLCall(glDeleteBuffers(1, &rendererID));
}

void VertexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
}

void VertexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
