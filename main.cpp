#include <vector>
#include "raylib.h"
#include "particle.hpp"

void spawnAlignedParticle(std::vector<dynamics::particle>& collective, vec2::Vector2f center, int count, float radius);

int main() {

    // WINDOW CONFIG
    constexpr unsigned short sizeX = 1440;
    constexpr unsigned short sizeY = 1280;
    constexpr unsigned short fpsTarget = 240;

    vec2::Vector2f screenSize = { (float)sizeX, (float)sizeY };

    const Color backgroundColor = {34, 34, 34, 255};

    InitWindow(sizeX, sizeY, "Shax's Physics Engine");
    SetTargetFPS(fpsTarget);

    // PARTICLE INIT
    constexpr short unsigned int particleCount = 100000;

    std::vector<dynamics::particle> collective;
    collective.reserve(particleCount);
    spawnAlignedParticle(collective, screenSize/2.0f, particleCount, radius);

    //PHYSICS LOOP
    
    //constants
    float gravity = 800.0f;
    constexpr float physicsTimeStep = 1.0f/480.0f;
    constexpr float squarePhysicsStep = physicsTimeStep * physicsTimeStep;

    float timeAccumulator = 0.0f;
    vec2::Vector2f accel = { 0.0f, gravity };

    while (!WindowShouldClose()) {
        timeAccumulator += GetFrameTime();

        while (timeAccumulator >= physicsTimeStep) {
            for (int i = 0; i < particleCount; i++) {
                dynamics::particle& circleData = collective[i];

                vec2::Vector2f nextPos = circleData.pos * 2.0 - circleData.oldPos + accel * squarePhysicsStep;
                circleData.oldPos = circleData.pos;
                circleData.pos = nextPos;
            }

            timeAccumulator -= physicsTimeStep;
        }

        BeginDrawing();
        ClearBackground(backgroundColor);
        DrawFPS(10, 10);

        for (int i = 0; i < particleCount; i++) {
            dynamics::particle& circleData = collective[i];
            DrawCircle((int)circleData.pos.x, (int)circleData.pos.y, radius, particleColor);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
};

void spawnAlignedParticle(std::vector<dynamics::particle>& collective, vec2::Vector2f center, int count, float radius) {
    int side = ceil(sqrtf((float)count));
    float spacing = radius * 2.0f;
    float offsetToCenter = (side * spacing) / 2.0f;

    //center = center / 2.0f;

    for (int i = 0; i < count; ++i) {
        int row = i / side;
        int col = i % side;

        dynamics::particle element = dynamics::create();

        element.pos.x = center.x - offsetToCenter + (col * spacing);
        element.pos.y = center.y - offsetToCenter + (row * spacing);
        element.oldPos = element.pos;

        collective.push_back(element);
    }
}