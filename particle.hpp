#include "raylib.h"
#include "vector2.hpp"

inline constexpr Color particleColor = { 192, 192, 192, 255 };
inline constexpr float radius = 1.0f;

namespace dynamics {
    struct particle {
        vec2::Vector2d oldPos;
        vec2::Vector2d pos;
        vec2::Vector2d accel;
    };

    particle create();
}