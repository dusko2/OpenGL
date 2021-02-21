#pragma once

#include "../Utils/IntTypes.h"

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

    private:
        static void LogError(const char* message);
        static void LogInfo(const char* message);
        static void GLDebugCallback(
            uint32 source,
            uint32 type,
            uint32 id,
            uint32 severity,
            int32 length,
            const char* message,
            const void* userParam
        );
};
