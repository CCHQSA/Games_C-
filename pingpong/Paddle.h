#pragma once
#include<raylib.h>
#include"Settings.h"

class Paddle
{
public:
    Paddle(int x, int y, int width, int height, int speed, Color color);
    void Draw() const;
    void UpdatePlayer(int windowHeight);
    int GetX() const;
    int GetY() const;
    int GetHeight() const;
    int GetWidth() const;

protected:
    int x;
    int y;
    int width;
    int height;
    int speed;
    Color color;

    void LimitMovement();
};