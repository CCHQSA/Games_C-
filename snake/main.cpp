#include"Settings.h"
#include"Game.h"
int main()
{
    Game game(settings::windowWidth, settings::windowHeight, settings::fps, settings::title, settings::cellSize, settings::rows, settings::columns);

    while (!WindowShouldClose())
    {
        game.Tick();
    }
    
    return 0;
}