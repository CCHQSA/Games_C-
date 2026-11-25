#pragma once
#include <raylib.h>

class Food
{
public:
    Food(int row, int column, int size);

    void Update();
    void Draw() const;
    void SetPosition(int newRow, int newColumn);

    int GetRow() const { return row; }
    int GetColumn() const { return column; }

private:
    int row;
    int column;
    const int size;
};
