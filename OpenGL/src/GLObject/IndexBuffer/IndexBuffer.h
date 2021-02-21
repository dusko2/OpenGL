#pragma once

#include "../GLObject.h"
#include "../../Utils/IntTypes.h"

class IndexBuffer : public GLObject {

	private:
		uint32 count;

	public:
		IndexBuffer(const uint32* data, uint32 count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		inline const uint32& GetCount() const {
			return count;
		}
};
