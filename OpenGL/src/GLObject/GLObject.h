#pragma once

#include "../Utils/IntTypes.h"

class GLObject {

    private:
        const char* className;

    protected:
        uint32 rendererID = 0;

    public:
        GLObject(const char* name);
        ~GLObject();

        inline uint32 GetRendererID() { return rendererID; }
};
