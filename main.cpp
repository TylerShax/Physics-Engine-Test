#include <vector>
#include <malloc.h>
#include "graphics.hpp"
#include "particle.hpp"
#include "physics.hpp"

void SpawnAlignedParticles(float* positionsX, float* positionsY, float* OLDpositionsX, float* OLDpositionsY);

int main() {
    graphics::initWindow();

    float *positionsX = (float*)_aligned_malloc(physics::particleCount * sizeof(float), 64);
    float *positionsY = (float*)_aligned_malloc(physics::particleCount * sizeof(float), 64);
    float *OLDpositionsX = (float*)_aligned_malloc(physics::particleCount * sizeof(float), 64);
    float *OLDpositionsY = (float*)_aligned_malloc(physics::particleCount * sizeof(float), 64);

    if (positionsX == NULL || positionsY == NULL || OLDpositionsX == NULL || OLDpositionsY == NULL)
        exit(1);

    SpawnAlignedParticles(positionsX, positionsY, OLDpositionsX, OLDpositionsY);

    //PHYSICS LOOP
    while (!WindowShouldClose()) {
        physics::timeAccumulator += GetFrameTime();

        physics::physicsLoop(positionsX, positionsY, OLDpositionsX, OLDpositionsY);

        graphics::beginDraw();
        graphics::drawAllParticles(positionsX, positionsY);
        graphics::endDraw();
    }

    _aligned_free(positionsX);
    _aligned_free(positionsY);
    _aligned_free(OLDpositionsX);
    _aligned_free(OLDpositionsY);

    return 0;
};

void SpawnAlignedParticles(float* positionsX, float* positionsY, float* OLDpositionsX, float* OLDpositionsY) {
    int side = static_cast<int>(ceil(sqrtf((float)physics::particleCount)));
    float spacing = dynamics::particleRadius * 2.0f;
    float offsetToCenter = (side * spacing) / 2.0f;

    vec2::Vector2f center = graphics::screenSize/2;

    for (int i = 0; i < physics::particleCount; ++i) {
        int row = i / side;
        int col = i % side;

        float posX = center.x - offsetToCenter + (col * spacing);
        float posY = center.y - offsetToCenter + (row * spacing);

        positionsX[i] = posX;
        positionsY[i] = posY;
        
        OLDpositionsX[i] = posX;
        OLDpositionsY[i] = posY;
    }
}