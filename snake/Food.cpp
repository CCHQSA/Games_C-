#include"Food.h"

Food::Food(const int row, const int column, const int size)
    :
    row(row),
    column(column),
    size(size)
{}

void Food::Draw() const 
{
    DrawRectangle(column*size, row*size, size, size, RED);
}

void Food::Update()
{
    
}

void Food::SetPosition(int newRow, int newColumn)
{
    row = newRow;
    column = newColumn;
}