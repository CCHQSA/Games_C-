#pragma once 
#include "raylibCpp.h"
#include <vector>
#include "Vec2.h"

class Board
{
private:
    class Cell{
        public:
            Cell();
            void SetColor(Color c_in);
            void Remove();
            Color GetColor() const;
            bool Exists() const;
        private:
        
        bool bExists;
        Color c;
    };
public:

    Board(
        Vec2<int> screenPos, Vec2<int> widthHeight,
        int cellSize_in, int padding_in
    );

    void SetCell(Vec2<int> pos, Color c);
    void DrawCell(Vec2<int> pos) const;
    void DrawCell(Vec2<int> pos, Color color) const;
    void Draw() const;
    void DrawBorder() const;
    bool CellExists(Vec2<int> pos) const;
    int GetWidth() const;
    int GetHeight() const;
    void ClearFullLines();
private:
    std::vector<Cell> cells;
    const int width;
    const int height;
    const int cellSize;
    const int padding;
    Vec2<int> screenPos;
};
