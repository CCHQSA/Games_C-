#pragma once
#include <deque>
#include <raylib.h>
#include "Grid.h"

struct Cell {
    int row;
    int col;

    bool operator==(const Cell& other) const {
        return row == other.row && col == other.col;
    }
};

enum class MoveResult {
    None,
    Moved,
    AteFood,
    Crashed
};

class Snake
{
public:
    Snake(int startRow, int startCol, int cellSize, Grid& grid);

    MoveResult Update(Grid& grid);
    void Draw() const;

private:
    void HandleInput();
    bool CheckSelfCollision() const;

private:
    std::deque<Cell> body;
    Cell direction;
    Cell nextDirection;
    int cellSize;

    float moveTimer = 0.0f;
    const float moveInterval = 0.15f;
};
