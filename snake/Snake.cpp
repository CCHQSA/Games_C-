#include "Snake.h"

Snake::Snake(int startRow, int startCol, int cellSize, Grid& grid)
    : cellSize(cellSize), direction({0, 1}), nextDirection({0, 1})
{
    // Spawn 3 segments and immediately register them on the grid
    for (int i = 0; i < 3; ++i)
    {
        Cell segment = {startRow, startCol - i};
        body.push_back(segment);
        grid.SetCell(segment.row, segment.col, 1);
    }
}

void Snake::HandleInput()
{
    if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && direction.row != 1)         nextDirection = {-1, 0};
    else if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && direction.row != -1) nextDirection = {1, 0};
    else if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && direction.col != 1)  nextDirection = {0, -1};
    else if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))&& direction.col != -1) nextDirection = {0, 1};
}

MoveResult Snake::Update(Grid& grid)
{
    HandleInput();

    moveTimer += GetFrameTime();
    if (moveTimer < moveInterval)
    {
        return MoveResult::None;
    }
    moveTimer = 0.0f;

    direction = nextDirection;
    Cell nextHead = { body.front().row + direction.row, body.front().col + direction.col };

    if (nextHead.row < 0 || nextHead.row >= grid.GetRows() ||
        nextHead.col < 0 || nextHead.col >= grid.GetColumns())
    {
        return MoveResult::Crashed;
    }

    bool ateFood = (grid.GetCell(nextHead.row, nextHead.col) == 2);

    body.push_front(nextHead);
    grid.SetCell(nextHead.row, nextHead.col, 1);

    if (!ateFood)
    {
        Cell tail = body.back();
        grid.SetCell(tail.row, tail.col, 0);
        body.pop_back();
    }

    if (CheckSelfCollision())
    {
        return MoveResult::Crashed;
    }

    return ateFood ? MoveResult::AteFood : MoveResult::Moved;
}

bool Snake::CheckSelfCollision() const
{
    const Cell& head = body.front();
    for (size_t i = 1; i < body.size(); ++i)
    {
        if (body[i] == head) return true;
    }
    return false;
}

void Snake::Draw() const
{
    for (size_t i = 0; i < body.size(); ++i)
    {
        Color color = (i == 0) ? LIME : GREEN;
        DrawRectangle(
            body[i].col * cellSize + 1,
            body[i].row * cellSize + 1,
            cellSize - 2,
            cellSize - 2,
            color
        );
    }
}