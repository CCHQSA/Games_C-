#pragma once
#include <raylib.h>
#include <random>

namespace settings
{
    // Window settings
    inline constexpr int windowWidth = 1600;
    inline constexpr int windowHeight = 800;
    inline constexpr int fps = 60;
    inline constexpr const char* title = "Title";

    // Text settings
    inline constexpr int fontSize = (windowHeight + windowWidth) / 100;

    // Bird settings
    inline constexpr int birdHeight = windowHeight * 0.05;
    inline constexpr int birdWidth = windowWidth * 0.05;
    inline constexpr int initialX = windowWidth * 0.05;
    inline constexpr int initialY = windowHeight / 2;
    inline constexpr float jumpForce = -windowHeight * 0.5f;
    inline constexpr float gravity = windowHeight * 1.5f;


    // Pipe settings
    inline constexpr int pipeWidth = windowWidth * 0.1;
    inline constexpr float pipeInitialX = static_cast<float>(windowWidth);
    inline constexpr int topPipeInitialY = 0;
    inline constexpr int gap = windowHeight * 0.20;
    inline constexpr float initialSpeed = 300.0f;

    // Random
    inline std::mt19937 gen{std::random_device{}()};

    inline int getRandomInt(int min, int max)
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }
}
