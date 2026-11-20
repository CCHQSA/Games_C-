#pragma once
#include<raylib.h>
#include"Bird.h"
#include<vector>
#include"Pipe.h"

class Game
{
public: 
    Game();
    void Tick();
private: 
    int windowWidth;
    int windowHeight;
    const int fps;
    const char* title;
    int score = 0;
    Bird bird;
    std::vector<Pipe> pipes;

private:
    void Draw();
    void Update();
    void Refill();
    void DrawPipes();
    void UpdatePipes(float dt);
    bool CheckCollisions(Pipe currPipe);
    void Restart();
    void StopPipes();
    bool gameOver = false;
    void AddScore(Pipe& currPipe);
};