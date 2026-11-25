// Grid.h
#pragma once
#include <raylib.h>

class Grid
{
public:
    Grid(int rows, int columns, int cellSize);
    ~Grid();

    Grid(const Grid&) = delete;
    Grid& operator=(const Grid&) = delete;

    void Draw() const;
    int GetCell(int row, int col) const;
    void SetCell(int row, int col, int value);
    int GetRows() const;
    int GetColumns() const;

private:
    int rows;
    int columns;
    int cellSize;
    int** cells;
};
