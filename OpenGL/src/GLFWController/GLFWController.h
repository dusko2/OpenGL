#pragma once

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
};
