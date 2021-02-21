#pragma once

#include <vector>

#include "../../Utils/IntTypes.h"

struct VertexBufferLayoutElement {

	public:
		uint32 type;
		uint32 count;
		bool normalized;
};

class VertexBufferLayout {

	private:
		std::vector<VertexBufferLayoutElement> elements;
		uint32 stride;

	public:
		VertexBufferLayout();

		template<typename T>
		void Add(uint32 count, bool normalized = false);

		inline const auto& GetElements() const {
			return elements;
		}

		inline const uint32 GetStride() const {
			return stride;
		}
};
