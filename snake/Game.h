#pragma once
#include <random>
#include "Grid.h"
#include "Food.h"
#include "Snake.h"

class Game
{
public:
    Game(
        const int windowWidth,
        const int windowHeight,
        const int fps,
        const char* title,
        const int cellSize,
        const int rows,
        const int columns
    );
    
    ~Game();

    void Tick();

private:
    void Draw() const;
    void Update();
    void GenerateFood();

private:
    const int windowWidth;
    const int windowHeight;
    const int fps;
    const char* title;

    const int cellSize;
    const int rows;
    const int columns;

    Grid grid;
    Food food;
    std::mt19937 rng;

    Snake snake;
    bool isGameOver = false; // Add this line
};
