#pragma once
#include <raylib.h>
#include "Ball.h"
#include "CpuPaddle.h"


class Game
{
public:
    Game();
    ~Game() noexcept;
    void Tick();
    void Draw();
    void Update();
    void CheckPaddlesCollision();

private:
    const int windowWidth;
    const int windowHeight;
    const int fps;
    const char* title;

    int playerScore = 0;
    int cpuScore = 0;

    Ball ball;
    Paddle playerPaddle;
    CpuPaddle cpuPaddle;
};
