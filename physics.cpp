#include <omp.h>
#include "physics.hpp"
#include "vector2.hpp"

namespace physics {
    void checkParticleCollisions() {
        //TODO: particle<->particle collisions
    };

    void checkWallCollisions() {
        //TODO: wall collisions
    };

    void physicsStep(bool force, float* positionsX, float* positionsY, float* OLDpositionsX, float* OLDpositionsY) {
        if (physics::timeAccumulator >= physics::physicsTimeStep || force == true) {

            #pragma omp paralell for schedule(static)
            for (auto i = 0u; i < physics::particleCount; ++i) {

                float PosX = positionsX[i];
                float PosY = positionsY[i];
                float oldPosX = OLDpositionsX[i];
                float oldPosY = OLDpositionsY[i];
                //vec2::Vector2f vPos = { positionsX[i], positionsY[i] };
                //vec2::Vector2f oldvPos = { OLDpositionsX[i], OLDpositionsY[i] };
                //vec2::Vector2f nextPos = vPos * 2.0 - oldvPos + physics::gravity * physics::squarePhysicsStep;
                float nextPosX = PosX * 2.0f - oldPosX + physics::gravity.x * physics::squarePhysicsStep;
                float nextPosY = PosY * 2.0f - oldPosY + physics::gravity.y * physics::squarePhysicsStep;
                
                OLDpositionsX[i] = PosX;
                OLDpositionsY[i] = PosY;
                positionsX[i] = nextPosX;
                positionsY[i] = nextPosY;
            }

            if (physics::timeAccumulator >= physics::physicsTimeStep)
                physics::timeAccumulator -= physics::physicsTimeStep;
        }
    };

    void physicsLoop(float* positionsX, float* positionsY, float* OLDpositionsX, float* OLDpositionsY) {
        for (auto i = 0u; i < 5; ++i) {
            if (physics::timeAccumulator < physics::physicsTimeStep)
                break;
            physics::physicsStep(false, positionsX, positionsY, OLDpositionsX, OLDpositionsY);
        }
    };
}