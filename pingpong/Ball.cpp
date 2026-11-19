#include "Ball.h"

Ball::Ball(int x, int y, int radius, Color color)
    :
    x(x),
    y(y),
    radius(radius),
    speedX(settings::initialBallSpeedX),
    speedY(settings::initialBallSpeedY),
    color(color)
{
}

void Ball::Draw() const
{   
    DrawCircle(x, y, static_cast<float>(radius), color);
}

void Ball::Reset()
{
    x = settings::initialBallX;
    y = settings::initialBallY;

    int speeChoice[2] = {-1, 1};
    speedX *= speeChoice[GetRandomValue(0,1)];
    speedY *= speeChoice[GetRandomValue(0,1)];
}

void Ball::Update(int& playerScore, int& cpuScore) {
    x += speedX;
    y += speedY;

    if (x + radius >= GetScreenWidth())
    {
        playerScore++;
        Reset();
    } 
    
    if(x - radius <= 0) 
    {
        cpuScore++;
        Reset();
    }
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speedY *= -1;
    }
}

int Ball::GetY() const
{
    return y;
}

int Ball::GetX() const
{
    return x;
}

int Ball::GetRadius() const
{
    return radius;
}

void Ball::ReverseSpeed()
{
    speedX *= -1;
}