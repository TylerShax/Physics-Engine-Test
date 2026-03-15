#pragma once
#include <vector>
#include "vector2.hpp"
#include "raylib.h"

namespace graphics {
    // WINDOW CONFIG
    inline vec2::Vector2f screenSize = { 1440.0f, 1280.0f };
    inline constexpr unsigned short fpsTarget = 240;
    inline const Color backgroundColor = {34, 34, 34, 255};

    // METHODS
    void initWindow();
    void beginDraw();
    void endDraw();
    void terminateWindow();

    // SHADER METHODS
    void loadAssets();
    void unloadAssets();

    // INTERACTIONS
    void drawAllParticles(float* positionsX, float* positionsY);
}