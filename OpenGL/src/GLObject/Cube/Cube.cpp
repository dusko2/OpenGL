#include <glad/glad.h>

#include "../Quad/Quad.h"
#include "../Vertex/Vertex.h"

#include "Cube.h"

namespace Archiv {

    Vertex backSide[] = {
        Vertex {-0.25f, -0.25f, -0.25f, 0.0f, 0.0f },
        Vertex { 0.25f, -0.25f, -0.25f, 1.0f, 0.0f },
        Vertex { 0.25f,  0.25f, -0.25f, 1.0f, 1.0f },
        Vertex { 0.25f,  0.25f, -0.25f, 1.0f, 1.0f },
        Vertex {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f },
        Vertex {-0.25f, -0.25f, -0.25f, 0.0f, 0.0f }
    };

    Vertex frontSide[] = {
        Vertex {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f },
        Vertex { 0.25f, -0.25f,  0.25f, 1.0f, 0.0f },
        Vertex { 0.25f,  0.25f,  0.25f, 1.0f, 1.0f },
        Vertex { 0.25f,  0.25f,  0.25f, 1.0f, 1.0f },
        Vertex {-0.25f,  0.25f,  0.25f, 0.0f, 1.0f },
        Vertex {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f }
    };

    Vertex leftSide[] = {
        Vertex {-0.25f,  0.25f,  0.25f, 1.0f, 1.0f },
        Vertex {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f },
        Vertex {-0.25f, -0.25f, -0.25f, 0.0f, 0.0f },
        Vertex {-0.25f, -0.25f, -0.25f, 0.0f, 0.0f },
        Vertex {-0.25f, -0.25f,  0.25f, 1.0f, 0.0f },
        Vertex {-0.25f,  0.25f,  0.25f, 1.0f, 1.0f }
    };

    Vertex rightSide[] = {
        Vertex { 0.25f,  0.25f,  0.25f, 1.0f, 1.0f },
        Vertex { 0.25f,  0.25f, -0.25f, 0.0f, 1.0f },
        Vertex { 0.25f, -0.25f, -0.25f, 0.0f, 0.0f },
        Vertex { 0.25f, -0.25f, -0.25f, 0.0f, 0.0f },
        Vertex { 0.25f, -0.25f,  0.25f, 1.0f, 0.0f },
        Vertex { 0.25f,  0.25f,  0.25f, 1.0f, 1.0f }
    };

    Vertex bottomSide[] = {
        Vertex {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f },
        Vertex { 0.25f, -0.25f, -0.25f, 1.0f, 1.0f },
        Vertex { 0.25f, -0.25f,  0.25f, 1.0f, 0.0f },
        Vertex { 0.25f, -0.25f,  0.25f, 1.0f, 0.0f },
        Vertex {-0.25f, -0.25f,  0.25f, 0.0f, 0.0f },
        Vertex {-0.25f, -0.25f, -0.25f, 0.0f, 1.0f }
    };

    Vertex topSide[] = {
        Vertex {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f },
        Vertex { 0.25f,  0.25f, -0.25f, 1.0f, 1.0f },
        Vertex { 0.25f,  0.25f,  0.25f, 1.0f, 0.0f },
        Vertex { 0.25f,  0.25f,  0.25f, 1.0f, 0.0f },
        Vertex {-0.25f,  0.25f,  0.25f, 0.0f, 0.0f },
        Vertex {-0.25f,  0.25f, -0.25f, 0.0f, 1.0f }
    };

    Cube::Cube() {
        sides[CubeSide::Top]    = new Quad(topSide,    "res/textures/grass-top-420x420.png", true);
        sides[CubeSide::Bottom] = new Quad(bottomSide, "res/textures/dirt.png", true);
        sides[CubeSide::Left]   = new Quad(leftSide,   "res/textures/grass-side-420x420.jpeg", false);
        sides[CubeSide::Right]  = new Quad(rightSide,  "res/textures/grass-side-420x420.jpeg", false);
        sides[CubeSide::Front]  = new Quad(frontSide,  "res/textures/grass-side-420x420.jpeg", false);
        sides[CubeSide::Back]   = new Quad(backSide,   "res/textures/grass-side-420x420.jpeg", false);

        position = new glm::vec3(0.0f, 0.0f, 0.0f);
    }

    Cube::~Cube() {
        delete position;
    }
}
