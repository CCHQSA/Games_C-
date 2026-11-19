#include "TetrominoFactory.h"
#include <algorithm>

TetrominoFactory::TetrominoFactory(Board& board)
    :
    board(board),
    rng(std::random_device{}())
{
    Refill();
}

Tetromino* TetrominoFactory::GetTetromino()
{
    if (!tetrominos.empty())
    {
        TetrominoType type = tetrominos.back();
        tetrominos.pop_back();

        switch (type)
        {
            case TetrominoType::Straight:
                return new Straight(board);
            case TetrominoType::Square:
                return new Square(board);
            case TetrominoType::Tee:
                return new Tee(board);
            case TetrominoType::Jay:
                return new Jay(board);
            case TetrominoType::El:
                return new El(board);
            case TetrominoType::SkewS:
                return new SkewS(board);
            case TetrominoType::SkewZ:
                return new SkewZ(board);
            default:
                return nullptr;
        }
    }
    else
    {
        Refill();
        return GetTetromino();
    }
}

void TetrominoFactory::Refill()
{
    tetrominos = {
        TetrominoType::Straight,
        TetrominoType::Square,
        TetrominoType::Tee,
        TetrominoType::Jay,
        TetrominoType::El,
        TetrominoType::SkewS,
        TetrominoType::SkewZ
    };

    std::shuffle(tetrominos.begin(), tetrominos.end(), rng);
}
