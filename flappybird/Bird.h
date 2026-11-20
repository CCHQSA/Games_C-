#pragma once
#include"Settings.h"


class Bird
{
public:
    Bird();
    void Draw() const;
    void Update(float dt);
    float GetX() const;
    float GetY() const;
    float GetWidth() const;
    float GetHeight() const;
    void Reset();

private:
    float y;
    float x = settings::initialX;
    const float width = settings::birdWidth;
    const float height = settings::birdHeight;

    float velocity = 0.0f;
    float gravity = settings::gravity;
    float jumpForce = settings::jumpForce;

private: 
    void CheckCollisionWithScreen();
};
