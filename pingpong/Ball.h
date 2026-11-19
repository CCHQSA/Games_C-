#pragma once
#include <raylib.h>
#include "Settings.h"

class Ball
{
public:
    Ball(int x, int y, int radius, Color color);
    void Draw() const;
    void Update(int& playerScore, int& cpuScore);
    void Reset();
    int GetY() const;
    int GetX() const;
    int GetRadius() const;
    void ReverseSpeed();

private:
    int x;
    int y;
    int radius;
    int speedX, speedY;
    Color color;
};
