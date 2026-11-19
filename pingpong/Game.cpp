#include "Game.h"
#include "Settings.h"

Game::Game()
    :
    windowWidth(settings::windowWidth),
    windowHeight(settings::windowHeight),
    fps(settings::fps),
    title("Title"),
    ball(settings::initialBallX, settings::initialBallY, settings::ballRadius, settings::ballColor),
    playerPaddle(settings::paddleX, settings::initialPaddleY, settings::paddleWidth, settings::paddleHeight, settings::paddleSpeed, settings::paddleColor),
    cpuPaddle(settings::cpuPaddleX, settings::initialCpuPaddleY, settings::cpuPaddleWidth, settings::cpuPaddleHeight, settings::paddleSpeed, settings::cpuPaddleColor)
{
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(fps);
}

Game::~Game() noexcept
{
    CloseWindow();
}

void Game::Tick()
{
    Update();
    BeginDrawing();
    Draw();
    EndDrawing();
}

void Game::Draw()
{
    ClearBackground(BLACK);

    DrawText(
        TextFormat("%d", playerScore), 
        settings::windowWidth * 0.1f, 
        settings::windowHeight * 0.05f, 
        (settings::windowHeight + settings::windowWidth) * 0.1f, 
        WHITE
    );

    DrawText(
        TextFormat("%d", cpuScore), 
        (settings::windowWidth - settings::windowWidth * 0.2f), 
        settings::windowHeight * 0.05f, 
        (settings::windowHeight + settings::windowWidth) * 0.1f, 
        WHITE
    );

    DrawLine
    (
        settings::startPosX,
        settings::startPosY,
        settings::endPosX,
        settings::endPosY,
        settings::lineColor
    );

    ball.Draw();
    playerPaddle.Draw();
    cpuPaddle.Draw();
}

void Game::Update()
{
    playerPaddle.UpdatePlayer(windowHeight);
    cpuPaddle.Update(ball.GetY(), GetScreenHeight());
    ball.Update(playerScore, cpuScore);
    CheckPaddlesCollision();

}

void Game::CheckPaddlesCollision()
{
    if (
        CheckCollisionCircleRec(
            Vector2{(float)ball.GetX(), (float)ball.GetY()},
            (float)ball.GetRadius(),
            Rectangle{(float)playerPaddle.GetX(), (float)playerPaddle.GetY(), (float)playerPaddle.GetWidth(), (float)playerPaddle.GetHeight()}
        )
    )
    {
        ball.ReverseSpeed();
    }

    if (
        CheckCollisionCircleRec(
            Vector2{(float)ball.GetX(), (float)ball.GetY()},
            (float)ball.GetRadius(),
            Rectangle{(float)cpuPaddle.GetX(), (float)cpuPaddle.GetY(), (float)cpuPaddle.GetWidth(), (float)cpuPaddle.GetHeight()}
        )
    )
    {
        ball.ReverseSpeed();
    }
}
