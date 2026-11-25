#include"Grid.h"

Grid::Grid(int rows, int columns, int cellSize)
    :
    rows(rows),
    columns(columns),
    cellSize(cellSize)
{
    cells = new int*[rows];

    for (int i = 0; i < rows; ++i)
    {
        cells[i] = new int[columns]{};
    }
}

Grid::~Grid()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] cells[i];
    }
    delete[] cells;
}

void Grid::Draw() const
{
    int gridWidth = columns * cellSize;
    int gridHeight = rows * cellSize;

    for (int r = 0; r <= rows; ++r)
    {
        int y = r * cellSize;
        DrawLine(0, y, gridWidth, y, {40, 40, 40, 255});
    }

    for (int c = 0; c <= columns; ++c)
    {
        int x = c * cellSize;
        DrawLine(x, 0, x, gridHeight, {40, 40, 40, 255});
    }
}


int Grid::GetCell(int row, int col) const
{
    int* cellRow = cells[row];
    return cellRow[col];
}

void Grid::SetCell(int row, int col, int value)
{
    int* cellRow = cells[row];
    cellRow[col] = value;
}

int Grid::GetRows() const { return rows; }
int Grid::GetColumns() const { return columns; }