#include "graphics.hpp"
#include "particle.hpp"
#include "physics.hpp"

namespace graphics {
    void initWindow() {
        int winSizeX = (int)graphics::screenSize.x;
        int winSizeY = (int)graphics::screenSize.y;
        
        InitWindow(winSizeX, winSizeY, "Shax's Physics Engine");
        SetTargetFPS(fpsTarget);
    }

    void beginDraw() {
        BeginDrawing();
        ClearBackground(backgroundColor);
        DrawFPS(10, 10);
    }

    void endDraw() {
        EndDrawing();
    }

    void terminateWindow() {
        CloseWindow();
    }

    void drawAllParticles(float* positionsX, float* positionsY) {
        for (auto i = 0u; i < physics::particleCount; ++i) {
            float posX = positionsX[i];
            float posY = positionsY[i];
            DrawRectangle(posX, posY, dynamics::particleRadius, dynamics::particleRadius, dynamics::particleColor);
        }
    }
}