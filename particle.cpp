#include "particle.hpp"

namespace dynamics {
    particle create() {
        particle newParticle = {
            vec2::Vector2d::zero(),
            vec2::Vector2d::zero(),
            vec2::Vector2d::zero()
        };

        return newParticle;
    };
}