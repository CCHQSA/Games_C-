#include"CpuPaddle.h"

void CpuPaddle::Update(int ballY, int windowHeight)
{   
    if((y + height / 2) < ballY)
    {
        y += speed;
    }
    else
    {
        y -= speed;
    }

    LimitMovement();
}