#pragma once
#include <vector>

class Position
{
protected:
    int x;
    int y;
public:
    Position(int i_x, int i_y);
    int getX();
    int getY();
    void setX(int i_x);
    void setY(int i_y);
};
class Tetromino
{
protected:
    unsigned char rotation;
    unsigned char shape;

    // Builds a vector for Position with x and y cooridnates of the tetromino
    std::vector<Position> minos;

public:
    Tetromino(unsigned char i_shape, const std::vector<std::vector<unsigned char>> &i_matrix); // Constructor takes instance of shape and matrix

    bool move_down(const std::vector<std::vector<unsigned char>>& i_matrix);
	bool reset(unsigned char i_shape, const std::vector<std::vector<unsigned char>>& i_matrix);

	unsigned char get_shape();

	void hard_drop(const std::vector<std::vector<unsigned char>>& i_matrix);
	void move_left(const std::vector<std::vector<unsigned char>>& i_matrix);
	void move_right(const std::vector<std::vector<unsigned char>>& i_matrix);
	void rotate(bool i_clockwise, const std::vector<std::vector<unsigned char>>& i_matrix);
	void update_matrix(std::vector<std::vector<unsigned char>>& i_matrix);

	std::vector<Position> get_ghost_minos(const std::vector<std::vector<unsigned char>>& i_matrix);
	std::vector<Position> get_minos();
};