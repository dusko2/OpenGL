#include <glad/glad.h>

#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout() : stride(0) {}

template<>
void VertexBufferLayout::Add<float>(uint32 count, bool normalized) {
    elements.push_back({ GL_FLOAT, count, normalized });
    stride += count * sizeof(float);
}

template<>
void VertexBufferLayout::Add<uint32>(uint32 count, bool normalized) {
    elements.push_back({ GL_UNSIGNED_INT, count, normalized });
    stride += count * sizeof(uint32);
}

template <>
void VertexBufferLayout::Add<uint8>(uint32 count, bool normalized) {
    elements.push_back({ GL_UNSIGNED_BYTE, count, normalized });
    stride += count * sizeof(uint8);
}

template void VertexBufferLayout::Add<float>(uint32 count, bool normalized = false);
template void VertexBufferLayout::Add<uint32>(uint32 count, bool normalized = false);
template void VertexBufferLayout::Add<uint8>(uint32 count, bool normalized = false);
