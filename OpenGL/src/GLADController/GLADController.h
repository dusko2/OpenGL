#pragma once

class GLADController {

	public:
        static GLADController& GetInstance() {
            static GLADController instance;
            return instance;
        }

    private:
        GLADController();

    public:
        ~GLADController();

        void Initialize();
};
