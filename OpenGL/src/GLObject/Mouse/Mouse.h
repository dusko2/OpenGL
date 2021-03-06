#pragma once

class Mouse {

    public:
        static Mouse& GetInstance() {
            static Mouse instance;
            return instance;
        }

    private:
        float lastX = 0.0f;
        float lastY = 0.0f;

        float offsetX = 0.0f;
        float offsetY = 0.0f;

    private:
        Mouse();

    public:
        void Update(float positionX, float positionY);

        inline float GetOffsetX() const {
            return offsetX;
        }

        inline float GetOffsetY() const {
            return offsetY;
        }

        void SetPosition(float x, float y);
};
