#pragma once

void GLClearError();
bool GLLogCall();

#define OpenGLAssert(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError(); x; OpenGLAssert(GLLogCall())
