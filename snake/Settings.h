#include<raylib.h>

namespace settings
{
    // Window settings 
    inline constexpr int windowWidth = 800;
    inline constexpr int windowHeight = 800;
    inline constexpr int fps = 60;
    inline constexpr const char* title = "Snake";

    // Grid settings 
    inline constexpr int cellSize = 40;
    inline constexpr int rows = windowHeight/cellSize, columns = windowWidth / cellSize;

}