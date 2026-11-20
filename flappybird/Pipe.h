#pragma once
#include "Settings.h"

class Pipe
{
public:
    Pipe(float startX = settings::pipeInitialX);
    void Draw() const;
    void Update(float dt);
    bool IsOffScreen() const;
    float GetX() const;
    float GetYTop() const;
    float GetYBottom() const;
    float GetWidth() const;
    float GetHeightTop() const;
    float GetHeightBottom() const;
    bool IsScored() const;
    void SetScored();

private:
    float x;
    int topPipeTopY = settings::topPipeInitialY;
    int topPipeHeight;

    int bottomPipeTopY;
    int bottomPipeHeight;

    int width = settings::pipeWidth;
    float speed = settings::initialSpeed;
    int gap = settings::gap;

    bool scored = false;


private:
    void SetHeightForPipes();
};
