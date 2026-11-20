#include "Pipe.h"
#include <raylib.h>

Pipe::Pipe(float startX)
    : x(startX)
{
    SetHeightForPipes();
}

void Pipe::Draw() const
{
    DrawRectangle(static_cast<int>(x), topPipeTopY, width, topPipeHeight, GREEN);
    DrawRectangle(static_cast<int>(x), bottomPipeTopY, width, bottomPipeHeight, GREEN);
}

void Pipe::Update(float dt) 
{
    x -= speed * dt;
}

void Pipe::SetHeightForPipes()
{
    topPipeHeight = settings::getRandomInt(50, settings::windowHeight - gap - 50);

    bottomPipeTopY = topPipeHeight + gap;
    bottomPipeHeight = settings::windowHeight - bottomPipeTopY;
}

float Pipe::GetX() const
{
    return x;
}

float Pipe::GetYTop() const
{
    return topPipeTopY;
}

float Pipe::GetYBottom() const
{
    return bottomPipeTopY;
}

float Pipe::GetHeightTop() const
{
    return topPipeHeight;bottomPipeHeight;
}

float Pipe::GetHeightBottom() const
{
    return bottomPipeHeight;
}

float Pipe::GetWidth() const
{
    return width;
}

bool Pipe::IsOffScreen() const
{
    return x + width < 0;
}

bool Pipe::IsScored() const
{
    return scored;
}

void Pipe::SetScored()
{
    scored = true;
}