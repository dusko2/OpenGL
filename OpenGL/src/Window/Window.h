#pragma once

#include "../Utils/IntTypes.h"

struct GLFWwindow;

class Window {

    public:
        Window(GLFWwindow* context, uint32 width, uint32 height, const char* title);
        ~Window();

        void Initialize();
        void Show();

        bool ShouldClose();

    private:
        static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);

    private:
        GLFWwindow* context;
        float width;
        float height;
        const char* title;
};
