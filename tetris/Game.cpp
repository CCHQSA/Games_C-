#include <assert.h>
#include "Game.h"
#include "raylibCpp.h"
#include "Settings.h"
#include "TetrominoFactory.h"

Game::Game(int width, int height, int fps, std::string title)
    :
    board(
        settings::boardPosition,
        settings::boardWidthHeight,
        settings::cellSize,
        settings::padding
    ),
    tetrominoFactory(board),
    tetromino(tetrominoFactory.GetTetromino())
{
    assert(GetWindowHandle());
    InitWindow(width, height, title.c_str());
    SetTargetFPS(fps);
}

Game::~Game() noexcept
{
    assert(GetWindowHandle());
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Draw()
{
    ClearBackground(BLACK);
    board.Draw();
    tetromino->Draw();
}

void Game::Update()
{
    if (IsKeyPressed(KEY_E))
    {
        tetromino->RotateClockWise();
    }
    if (IsKeyPressed(KEY_Q))
    {
        tetromino->RotateCounterClockWise();
    }

    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    {
        tetromino->MoveLeft();
    }
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    {
        tetromino->MoveRight();
    }

    float currentInterval = (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) ? 0.05f : fallInterval;
    fallTimer += GetFrameTime();

    if (fallTimer >= currentInterval)
    {
        fallTimer = 0.0f;

        if (!tetromino->MoveDown())
        {
            tetromino->LockToBoard();
            board.ClearFullLines();
            tetromino.reset(tetrominoFactory.GetTetromino());
        }
    }
}
