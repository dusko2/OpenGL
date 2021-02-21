#include <iostream>

#include <glad/glad.h>

#include "GLUtils.h"
#include "../Utils/IntTypes.h"

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall() {
	while (uint32 error = glGetError()) {
		std::cout << ">> [OpenGL] Error = " << error << std::endl;
		return false;
	}

	return true;
}
