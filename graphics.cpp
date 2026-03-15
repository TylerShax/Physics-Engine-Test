#include "raylib.h"
#include "rlgl.h"
#include "graphics.hpp"
#include "particle.hpp"
#include "physics.hpp"

namespace graphics {
    Shader circleShader;
    Texture2D whiteTexture;

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

    void loadAssets() {
        circleShader = LoadShader(0, "circle.fs");

        if (IsShaderReady(circleShader)) {
            TraceLog(LOG_ERROR, "Shader critical error.");
        }

        Image whiteImage = GenImageColor(1, 1, WHITE);
        whiteTexture = LoadTextureFromImage(whiteImage);
        UnloadImage(whiteImage);
    };

    void unloadAssets() {
        UnloadShader(circleShader);
        UnloadTexture(whiteTexture);
    };

    void drawAllParticles(float* positionsX, float* positionsY) {
        constexpr float circleRadius = dynamics::particleRadius;
        constexpr float circleSize = circleRadius * 2.0f;
       
        //BeginShaderMode(circleShader);
        //for (auto i = 0u; i < physics::particleCount; ++i) {
        //    DrawTexturePro(
        //        whiteTexture,
        //        { 0.0f, 0.0f, 1.0f, 1.0f },
        //        { positionsX[i] - circleRadius, positionsY[i] - circleRadius, circleSize, circleSize },
        //        { 0.0f, 0.0f },
        //        0.0f,
        //        dynamics::particleColor
        //    );
        //}
        //EndShaderMode();
    }
}