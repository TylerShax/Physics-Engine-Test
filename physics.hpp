#pragma once
#include <vector>
#include "vector2.hpp"

namespace physics {
    inline vec2::Vector2f gravity = { 0.0f, 800.0f };
    inline constexpr unsigned int particleCount = 1000000;

    inline float timeAccumulator = 0.0f;

    inline constexpr float physicsTimeStep = 1.0f/60.0f;
    inline constexpr float squarePhysicsStep = physicsTimeStep * physicsTimeStep;

    void checkParticleCollisions();
    void checkWallCollisions();

    void physicsStep(bool force, float* positionsX, float* positionsY, float* OLDpositionsX, float* OLDpositionsY);
    void physicsLoop(float* positionsX, float* positionsY, float* OLDpositionsX, float* OLDpositionsY);
}