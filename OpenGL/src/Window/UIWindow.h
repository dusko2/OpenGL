#pragma once

struct GLFWwindow;

class UIWindow {

    public:
        static UIWindow& GetInstance() {
            static UIWindow instance("Dusko Car", 1280, 720);
            return instance;
        }

    private:
        UIWindow(const char* title, int width, int height);

    public:
        ~UIWindow();

        void Initialize();
        void OnGladInit();
        void StartLoop();

        bool ShouldClose();

    private:
        static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);

    private:
        GLFWwindow* internalWindow;
        const char* title;
        int width;
        int height;
};
