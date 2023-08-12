#pragma once
#include <vector>

class Tetromino
{
protected:
    unsigned char rotation;
    unsigned char shape;

    class Position
    {
    public:
        int x;
        int y;
    };
    // Builds a vector for Position with x and y cooridnates of the tetromino
    std::vector<Position> block;

public:
    Tetromino();

    bool moveDown();
    void moveLeft();
    void moveRight();
    void rotate();

    void hardDrop();
    void updateMatrix();

    std::vector<Position> getBlock();
    std::vector<Position> getGhostBlock();
};