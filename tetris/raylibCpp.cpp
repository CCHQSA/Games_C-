#include "raylibCpp.h"
#include <assert.h>

void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
           pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()
    );
    

    ::DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);
}

void raycpp::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, float thick, Color color)
{
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
           pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()
    );

    assert(thick > 0);

    Rectangle rec = {
        static_cast<float>(pos.GetX()),
        static_cast<float>(pos.GetY()),
        static_cast<float>(widthHeight.GetX()),
        static_cast<float>(widthHeight.GetY())
    };

    DrawRectangleLinesEx(rec, thick, color);
}
