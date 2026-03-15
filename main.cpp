#include <vector>
#include "graphics.hpp"
#include "particle.hpp"
#include "physics.hpp"

void spawnAlignedParticle(std::vector<dynamics::particle>& collective, vec2::Vector2f center, int count, float radius);

int main() {

    graphics::initWindow();

    // PARTICLE INIT
    constexpr short unsigned int particleCount = 100000;

    std::vector<dynamics::particle> collective;
    collective.reserve(particleCount);
    spawnAlignedParticle(collective, graphics::screenSize/2.0f, particleCount, dynamics::particleRadius);

    //PHYSICS LOOP
    while (!WindowShouldClose()) {
        physics::timeAccumulator += GetFrameTime();

        while (physics::timeAccumulator >= physics::physicsTimeStep) {
            for (int i = 0; i < particleCount; i++) {
                dynamics::particle& circleData = collective[i];

                vec2::Vector2f nextPos = circleData.pos * 2.0 - circleData.oldPos + accel * physics::squarePhysicsStep;
                circleData.oldPos = circleData.pos;
                circleData.pos = nextPos;
            }

            physics::timeAccumulator -= physics::physicsTimeStep;
        }


    }

    

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