#pragma once
#include <raylib.h>

namespace settings
{
    // Window settings
    inline constexpr int windowWidth = 800;
    inline constexpr int windowHeight = 500;
    inline constexpr int fps = 120;

    // Ball params
    inline constexpr int initialBallX = windowWidth / 2;
    inline constexpr int initialBallY = windowHeight / 2;
    inline constexpr int initialBallSpeedX = 3;
    inline constexpr int initialBallSpeedY = 3;
    inline constexpr int ballRadius = 15;
    inline constexpr Color ballColor = {255, 255, 255, 255};

    // Player paddle params
    inline constexpr int paddleWidth = static_cast<int>(windowWidth - (windowWidth * 0.985f));
    inline constexpr int paddleHeight = windowHeight / 6;
    inline constexpr int paddleX = windowWidth / 100;
    inline constexpr int initialPaddleY = (windowHeight / 2) - (paddleHeight / 2);
    inline constexpr int paddleSpeed = 3;
    inline constexpr Color paddleColor = {255, 255, 255, 255};

    // CPU paddle params
    inline constexpr int cpuPaddleWidth = static_cast<int>(windowWidth - (windowWidth * 0.985f));
    inline constexpr int cpuPaddleHeight = windowHeight / 6;
    inline constexpr int cpuPaddleX = windowWidth - (windowWidth / 100) - cpuPaddleWidth;
    inline constexpr int initialCpuPaddleY = (windowHeight / 2) - (cpuPaddleHeight / 2);
    inline constexpr Color cpuPaddleColor = {255, 255, 255, 255};

    // Center line params
    inline constexpr int startPosX = windowWidth / 2;
    inline constexpr int startPosY = 0;
    inline constexpr int endPosX = windowWidth / 2;
    inline constexpr int endPosY = windowHeight;
    inline constexpr Color lineColor = {255, 255, 255, 255};
}
