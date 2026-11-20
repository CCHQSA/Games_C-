#include "Bird.h"

Bird::Bird()
    :
    y(settings::initialY)
{
}

void Bird::Draw() const
{
    DrawRectangle(x, y, width, height, YELLOW);
}

void Bird::Update(float dt)
{   
    CheckCollisionWithScreen();

    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP))
    {
        velocity = jumpForce;
    }
    
    velocity += gravity * dt;

    y += velocity * dt;

    CheckCollisionWithScreen();
}

void Bird::CheckCollisionWithScreen()
{
    if (y >= GetScreenHeight() - height)
    {
        y = GetScreenHeight() - height; 
        velocity = 0.0f;
    }
    else if (y <= 0)
    {
        y = 0;
        velocity = 0.0f;
    }
}

float Bird::GetX() const 
{
    return x;
}

float Bird::GetY() const 
{
    return y;
}

float Bird::GetWidth() const 
{
    return width;
}

float Bird::GetHeight() const 
{
    return height;
}

void Bird::Reset()
{
    y = settings::initialY;
    velocity = 0.0f;
}
