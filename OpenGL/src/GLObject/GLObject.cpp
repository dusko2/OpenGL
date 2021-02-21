#include <iostream>

#include "GLObject.h"

GLObject::GLObject(const char* name) : className(name) { }

GLObject::~GLObject() {
    std::cout << ">> [GLObject] Deallocating " << className << " with OpenGL ID = " << rendererID << std::endl;
}
