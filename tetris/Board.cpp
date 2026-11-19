#include "Board.h"
#include <assert.h>

bool Check_XY_Bounds(Vec2<int> pos, int width, int height);
int getIndex(Vec2<int> pos, int width);

Board::Cell::Cell()
    :
    bExists(false),
    c(WHITE)
{
}

void Board::Cell::SetColor(Color c_in)
{
    c = c_in;
    bExists = true;
}

void Board::Cell::Remove()
{
    bExists = false;
}

Color Board::Cell::GetColor() const
{
    return c;
}

bool Board::Cell::Exists() const
{
   return bExists;
}

Board::Board
    (
        Vec2<int> screenPos, Vec2<int> widthHeight,
        int cellSize_in, int padding_in
    )
        :
        screenPos(screenPos),
        width(widthHeight.GetX()),
        height(widthHeight.GetY()),
        cellSize(cellSize_in),
        padding(padding_in)
{
    assert(width > 0 && height > 0);
    assert(cellSize > 0);
    cells.resize(width * height);
}

bool Board::CellExists(Vec2<int> pos) const
{
    return cells[getIndex(pos, width)].Exists();
}

void Board::SetCell(Vec2<int> pos, Color c)
{   
    assert(Check_XY_Bounds(pos, width, height));
    int index = getIndex(pos, width);
    cells[index].SetColor(c);
}

void Board::DrawCell(Vec2<int> pos, Color color) const
{
    assert(Check_XY_Bounds(pos, width, height));
    int index = getIndex(pos, width);
    Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
    raycpp::DrawRectangle
    (
        topLeft,
        Vec2<int>{cellSize, cellSize} - padding,
        color
    );
}

void Board::DrawCell(Vec2<int> pos) const
{
    assert(Check_XY_Bounds(pos, width, height));
    Color color = cells[getIndex(pos, width)].GetColor();
    DrawCell(pos, color);
}

void Board::DrawBorder() const
{
    raycpp::DrawRectangleLinesEx(
        screenPos - (cellSize/2),
        Vec2{width*cellSize, height*cellSize} + (cellSize),
        cellSize/2, WHITE
    );
}

int Board::GetWidth() const{
    return width;
}

int Board::GetHeight() const{
    return height;
}

void Board::Draw() const
{
    for (int iY = 0; iY < height; iY++)
    {
        for(int iX = 0; iX < width; iX++)
        {
            if(CellExists({iX, iY}))
            {
                DrawCell({iX, iY});
            }
        }
    }
    DrawBorder();
}

bool Check_XY_Bounds(Vec2<int> pos, int width, int height)
{
    return pos.GetX() >= 0 && pos.GetX() < width &&
           pos.GetY() >= 0 && pos.GetY() < height;
}

int getIndex(Vec2<int> pos, int width)
{
    return pos.GetY() * width + pos.GetX();
}

void Board::ClearFullLines()
{

    for (int y = height - 1; y >= 0; --y)
    {
        bool isRowFull = true;

        for (int x = 0; x < width; ++x)
        {
            if (!CellExists({x, y}))
            {
                isRowFull = false;
                break;
            }
        }

        if (isRowFull)
        {
            for (int moveY = y; moveY > 0; --moveY)
            {
                for (int x = 0; x < width; ++x)
                {
                    int targetIndex = getIndex({x, moveY}, width);
                    int aboveIndex  = getIndex({x, moveY - 1}, width);
                    cells[targetIndex] = cells[aboveIndex];
                }
            }

            for (int x = 0; x < width; ++x)
            {
                cells[getIndex({x, 0}, width)].Remove();
            }

            ++y;
        }
    }
}
