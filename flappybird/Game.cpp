#include "Game.h"
#include "Settings.h"
#include <raylib.h>

Game::Game()
    :
    windowWidth(settings::windowWidth),
    windowHeight(settings::windowHeight),
    fps(settings::fps),
    title(settings::title),
    bird()
{
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(fps);
    Refill();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Draw()
{   
    ClearBackground({78, 192, 202, 255});

    bird.Draw();
    DrawPipes();


    DrawRectangle(0, 0, settings::windowWidth / 15, settings::windowHeight / 15, BLACK);
    DrawText(TextFormat("%i", score), 20, 20, settings::fontSize, WHITE);

    if (gameOver)
    {
        DrawText("Press R to restart", settings::windowWidth / 2, settings::windowHeight / 2, settings::fontSize, BLACK);
    }
}


void Game::Update()
{   
    if (gameOver)
    {   
        DrawText("Press R to restart", settings::windowWidth / 2, settings::windowHeight / 2, settings::fontSize, {0,0,0,255});
        if (IsKeyPressed(KEY_R))
        {
            Restart();
        }
        return;
    }

    float dt = GetFrameTime();
    bird.Update(dt);
    UpdatePipes(dt);
}

void Game::Refill()
{
    while(pipes.size() < 4)
    {
        float spawnX = pipes.empty() 
            ? settings::pipeInitialX 
            : pipes.back().GetX() + 520.0f;
        
        pipes.push_back(Pipe(spawnX));
    }
}

void Game::DrawPipes()
{
    for (const Pipe& p : pipes)
    {
        p.Draw();
    }
}

void Game::UpdatePipes(float dt)
{
    if(!pipes.empty())
    {
        for (Pipe& p : pipes)
        {
            p.Update(dt);
            if (CheckCollisions(p))
            {
                gameOver = true;
            }
            AddScore(p);
        }
    }

    if (!pipes.empty() && pipes[0].IsOffScreen())
    {
        pipes.erase(pipes.begin());
    }

    Refill();

}

bool Game::CheckCollisions(Pipe currPipe)
{
    Rectangle birdRec = Rectangle
    (
        bird.GetX(),
        bird.GetY(),
        bird.GetWidth(),
        bird.GetHeight()
    );

    Rectangle pipeRecTop = Rectangle
    (
        currPipe.GetX(),
        currPipe.GetYTop(),
        currPipe.GetWidth(),
        currPipe.GetHeightTop()
    );

    Rectangle pipeRecBottom = Rectangle
    (
        currPipe.GetX(),
        currPipe.GetYBottom(),
        currPipe.GetWidth(),
        currPipe.GetHeightBottom()
    );
    
    return CheckCollisionRecs(birdRec, pipeRecTop) || CheckCollisionRecs(birdRec, pipeRecBottom);
}

void Game::Restart()
{
    gameOver = false;
    bird.Reset();
    pipes.clear();
    score = 0;
    Refill();
}

void Game::AddScore(Pipe& currPipe)
{
    if (!currPipe.IsScored() && currPipe.GetX() + currPipe.GetWidth() < bird.GetX())
    {
        score++;
        currPipe.SetScored();
    }
}