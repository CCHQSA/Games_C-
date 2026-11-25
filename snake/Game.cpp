// Game.cpp
#include "Game.h"
#include <raylib.h>

Game::Game(
    const int windowWidth,
    const int windowHeight,
    const int fps,
    const char* title,
    const int cellSize,
    const int rows,
    const int columns
)
    :
    windowWidth(windowWidth),
    windowHeight(windowHeight),
    fps(fps),
    title(title),
    cellSize(cellSize),
    rows(rows),
    columns(columns),
    grid(rows, columns, cellSize),
    food(0, 0, cellSize),
    rng(std::random_device{}()),
    snake(rows / 2, columns / 2, cellSize, grid) // Spawns safely in center & marks grid
{
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(fps);
    GenerateFood(); // Guaranteed not to overlap with the snake
}

Game::~Game()
{
    CloseWindow();
}

void Game::Tick()
{
    Update();
    Draw();
}

void Game::Draw() const
{
    BeginDrawing();
    ClearBackground(BLACK);
    grid.Draw();
    food.Draw();
    snake.Draw();

    if (isGameOver)
    {
        DrawText("GAME OVER", windowWidth / 2 - 110, windowHeight / 2 - 20, 36, RED);
    }

    EndDrawing();
}

void Game::Update()
{
    if (isGameOver) return;

    MoveResult result = snake.Update(grid);

    if (result == MoveResult::AteFood)
    {
        GenerateFood();
    }
    else if (result == MoveResult::Crashed)
    {
        isGameOver = true;
    }
}

void Game::GenerateFood()
{
    int oldRow = food.GetRow();
    int oldCol = food.GetColumn();
    if (grid.GetCell(oldRow, oldCol) == 2)
    {
        grid.SetCell(oldRow, oldCol, 0);
    }

    std::uniform_int_distribution<int> rowDist(0, rows - 1);
    std::uniform_int_distribution<int> colDist(0, columns - 1);

    int randomRow;
    int randomCol;

    do
    {
        randomRow = rowDist(rng);
        randomCol = colDist(rng);
    } while (grid.GetCell(randomRow, randomCol) != 0);

    food.SetPosition(randomRow, randomCol);
    grid.SetCell(randomRow, randomCol, 2);
}

