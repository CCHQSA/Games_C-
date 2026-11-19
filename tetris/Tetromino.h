#pragma once 
#include"Vec2.h"
#include"raylibCpp.h"
#include"Board.h"
#include<assert.h>

class Tetromino
{
public:
    enum class Rotation{
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

public:
    virtual ~Tetromino() = default; 
    Tetromino(const bool* shape, int dimension, Color color,Board& board);
    void RotateClockWise();
    void RotateCounterClockWise();
    void Draw() const;
    bool Move(Vec2<int> delta);
    bool MoveDown();
    bool MoveLeft();
    bool MoveRight();
    bool IsColliding() const;
    void LockToBoard();
private:
    bool GetCell(int x, int y) const;
    Vec2<int> boardPos;
    Rotation currRotation;
    const bool* shape;
    const int dimension;
    Color color;
    Board& board;
};

class Straight : public Tetromino
{
public:
    Straight(Board& board)
        :
        Tetromino(shape, dimension, color, board)
    {
        static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
    }
private:
    static constexpr bool shape[] = {0, 0, 0, 0,
                                     1, 1, 1, 1,
                                     0, 0, 0, 0,
                                     0, 0, 0, 0
                                     };

    static constexpr int dimension = 4;                                
    static constexpr Color color = SKYBLUE;   
};

class Square : public Tetromino
{
public:
    Square(Board& board)
        :
        Tetromino(shape, dimension, color, board)
    {
        static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
    }
private:
    static constexpr bool shape[] = {1, 1,
                                     1, 1
                                     };

    static constexpr int dimension = 2;                                
    static constexpr Color color = YELLOW;   
};

class Tee : public Tetromino
{
public:
    Tee(Board& board)
        :
        Tetromino(shape, dimension, color, board)
    {
        static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
    }
private:
    static constexpr bool shape[] = {0, 1, 0,
                                     1, 1, 1,
                                     0, 0, 0
                                     };

    static constexpr int dimension = 3;                                
    static constexpr Color color = MAGENTA;   
};

class Jay : public Tetromino
{
public:
    Jay(Board& board)
        :
        Tetromino(shape, dimension, color, board)
    {
        static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
    }
private:
    static constexpr bool shape[] = {1, 0, 0,
                                     1, 1, 1,
                                     0, 0, 0
                                     };

    static constexpr int dimension = 3;                                
    static constexpr Color color = DARKBLUE;   
};

class El : public Tetromino
{
public:
    El(Board& board)
        :
        Tetromino(shape, dimension, color, board)
    {
        static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
    }
private:
    static constexpr bool shape[] = {0, 0, 1,
                                     1, 1, 1,
                                     0, 0, 0
                                     };

    static constexpr int dimension = 3;                                
    static constexpr Color color = ORANGE;   
};

class SkewS : public Tetromino
{
public:
    SkewS(Board& board)
        :
        Tetromino(shape, dimension, color, board)
    {
        static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
    }
private:
    static constexpr bool shape[] = {0, 1, 1,
                                     1, 1, 0,
                                     0, 0, 0
                                     };

    static constexpr int dimension = 3;                              
    static constexpr Color color = GREEN;   
};

class SkewZ : public Tetromino
{
public:
    SkewZ(Board& board)
        :
        Tetromino(shape, dimension, color, board)
    {
        static_assert(sizeof(shape) / sizeof(bool) == dimension * dimension);
    }
private:
    static constexpr bool shape[] = {1, 1, 0,
                                     0, 1, 1,
                                     0, 0, 0
                                     };

    static constexpr int dimension = 3;                              
    static constexpr Color color = RED;   
};
