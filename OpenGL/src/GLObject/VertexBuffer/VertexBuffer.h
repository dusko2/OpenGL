#pragma once

#include "../GLObject.h"

class VertexBufferLayout;

class VertexBuffer : public GLObject {

	public:
		VertexBuffer(const void* data, uint32 size);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
};
