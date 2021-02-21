#include <glad/glad.h>

#include "../GLUtils.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const uint32* data, uint32 count) : GLObject(__func__), count(count) {
	GLCall(glGenBuffers(1, &rendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
	GLCall(glDeleteBuffers(1, &rendererID));
}

void IndexBuffer::Bind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
}

void IndexBuffer::Unbind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
