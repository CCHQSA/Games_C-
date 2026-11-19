#include "TetrominoFactory.h"

Tetromino::Tetromino(const bool* shape, int dimension, Color color, Board& board)
    :
    shape(shape),
    dimension(dimension),
    color(color),
    boardPos(board.GetWidth() / 2 - dimension / 2, 0),
    board(board),
    currRotation(Rotation::UP)
{
}

void Tetromino::RotateClockWise()
{
    Rotation oldRotation = currRotation;
    currRotation = Rotation((int(currRotation) + 1) % 4);

    if (IsColliding())
    {
        currRotation = oldRotation;
    }
}

void Tetromino::RotateCounterClockWise()
{
    Rotation oldRotation = currRotation;
    if (currRotation == Rotation::UP)
    {
        currRotation = Rotation::LEFT;
    }
    else
    {
        currRotation = Rotation((int(currRotation) - 1));
    }

    if (IsColliding())
    {
        currRotation = oldRotation;
    }
}

void Tetromino::Draw() const
{
    for (int y = 0; y < dimension; ++y)
    {
        for (int x = 0; x < dimension; ++x)
        {
            if (GetCell(x, y))
            {
                Vec2<int> cellPos = boardPos + Vec2<int>{x, y};
                if (cellPos.GetY() >= 0)
                {
                    board.DrawCell(cellPos, color);
                }
            }
        }
    }
}

bool Tetromino::Move(Vec2<int> delta)
{
    boardPos += delta;

    if (IsColliding())
    {
        boardPos -= delta;
        return false;
    }

    return true;
}

bool Tetromino::MoveDown()  { return Move({0, 1}); }
bool Tetromino::MoveLeft()  { return Move({-1, 0}); }
bool Tetromino::MoveRight() { return Move({1, 0}); }

bool Tetromino::IsColliding() const
{
    for (int y = 0; y < dimension; y++)
    {
        for (int x = 0; x < dimension; x++)
        {
            if (!GetCell(x, y)) continue;

            Vec2<int> cellPos = boardPos + Vec2<int>{x, y};

            if (cellPos.GetX() < 0 || cellPos.GetX() >= board.GetWidth() ||
                cellPos.GetY() >= board.GetHeight())
            {
                return true;
            }

            if (cellPos.GetY() >= 0 && board.CellExists(cellPos))
            {
                return true;
            }
        }
    }
    return false;
}

void Tetromino::LockToBoard()
{
    for (int y = 0; y < dimension; ++y)
    {
        for (int x = 0; x < dimension; ++x)
        {
            if (GetCell(x, y))
            {
                Vec2<int> cellPos = boardPos + Vec2<int>{x, y};

                if (cellPos.GetY() >= 0)
                {
                    board.SetCell(cellPos, color);
                }
            }
        }
    }
}

bool Tetromino::GetCell(int x, int y) const
{
    switch (currRotation)
    {
        case Rotation::UP:    return shape[y * dimension + x];
        case Rotation::RIGHT: return shape[dimension * (dimension - 1) - (dimension * x) + y];
        case Rotation::DOWN:  return shape[(dimension * dimension - 1) - (dimension * y) - x];
        case Rotation::LEFT:  return shape[dimension - 1 + (dimension * x) - y];
    }
    return false;
}
