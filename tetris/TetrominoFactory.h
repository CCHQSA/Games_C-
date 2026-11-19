#pragma once
#include "Tetromino.h"
#include <vector>
#include <random>

class TetrominoFactory
{
public:
    enum class TetrominoType {
        Straight,
        Square,
        Tee,
        Jay,
        El,
        SkewS,
        SkewZ
    };

public:
    TetrominoFactory(Board& board);
    Tetromino* GetTetromino();

private:
    std::vector<TetrominoType> tetrominos;
    Board& board;
    std::mt19937 rng;

private:
    void Refill();
};
