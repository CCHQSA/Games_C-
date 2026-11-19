#include"Game.h"
#include<raylib.h>

int main()
{
    Game game;

    while (!WindowShouldClose())
    {
        game.Tick();
    }
    
    return 0;
}