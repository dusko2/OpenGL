#pragma once

#include "../Utils/IntTypes.h"

class Window;

class GLFWController {

    public:
        static GLFWController& GetInstance() {
            static GLFWController instance;
            return instance;
        }

    private:
        GLFWController();

    public:
        ~GLFWController();

        void Initialize();
        void Terminate();

        Window* CreateWindow(uint32 width, uint32 height, const char* title);
};
