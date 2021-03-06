#pragma once

#include <unordered_map>

#include "../../Math/Math.h"

namespace Archiv {

    enum class CubeSide : int {

        Top    = 0,
        Bottom = 1,
        Left   = 2,
        Right  = 3,
        Front  = 4,
        Back   = 5
    };

    class Quad;

    class Cube {

        private:
            std::unordered_map<CubeSide, Quad*> sides;
            glm::vec3* position;

        public:
            Cube();
            ~Cube();

            inline const std::unordered_map<CubeSide, Quad*>& GetSides() const {
                return sides;
            }

            inline Quad& GetSideQuad(CubeSide side) {
                return *(sides[side]);
            }

            inline const glm::mat4 GetModel() const {
                return glm::translate(glm::mat4(1.0f), *position);
            }

            inline void SetPosition(float x, float y, float z) {
                position->x = x;
                position->y = y;
                position->z = z;
            }
    };
}
