#pragma once
#include "Paddle.h"

class CpuPaddle : public Paddle
{
public:
    using Paddle::Paddle;
    void Update(int ballY, int windowHeight);
};
