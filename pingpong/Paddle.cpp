#include"Paddle.h"

Paddle::Paddle(int x, int y, int width, int height, int speed, Color color)
    : 
    x(x),
    y(y),
    width(width),
    height(height),
    speed(speed),
    color(color)
{
}

void Paddle::Draw() const
{
    DrawRectangle(x, y, width, height, color);
}

void Paddle::UpdatePlayer(int windowHeight)
{
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        y += speed;
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        y -= speed;
    }

    LimitMovement();
}

void Paddle::LimitMovement() {
    if (y < 0) {
        y = 0;
    }
    if (y + height > settings::windowHeight) {
        y = settings::windowHeight - height;
    }
}

int Paddle::GetX() const
{
    return x;
}

int Paddle::GetY() const 
{
    return y;
}

int Paddle::GetHeight() const
{
    return height;
}

int Paddle::GetWidth() const
{
    return width;
}