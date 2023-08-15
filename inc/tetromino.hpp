#pragma once

#include "SFML/Graphics.hpp"
#include "globals.hpp"

constexpr int shapes[7][4] =
        {
                {1, 3, 5, 7}, //I
                {2, 4, 5, 7}, //Z
                {3, 5, 4, 6}, //S
                {3, 5, 4, 7}, //T
                {2, 3, 5, 7}, //L
                {3, 5, 7, 6}, //J
                {2, 3, 4, 5}  //O
        };

namespace tetris
{
    class Cell
    {
    private:
        float _x, _y;
        int _shape_id;
        GameDataRef _data;
        sf::Sprite _cell_sprite; //hello world
    public:
        Cell(){}
        Cell(float x, float y, int shape_id, GameDataRef& data):_x(x), _y(y), _shape_id(shape_id), _data(data)
        {}
        void set_sprite()
        {
            _cell_sprite.setTexture(_data->assets.getTexture("ColorBox"));
            _cell_sprite.setTextureRect(sf::IntRect (30 *(_shape_id),0,30,30));
            _cell_sprite.setPosition(_x, _y);
        }
        void draw()
        {
            _data->window.draw(_cell_sprite);
        }
        void set_position(float x, float y)
        {
            _x=x;
            _y=y;
            set_sprite();
        }
        float get_x()
        {
            return _x;
        }
        float get_y()
        {
            return _y;
        }
    };
    class Tetromino
    {
    public:

        Cell cells[4];

        Tetromino(GameDataRef& data, int shape_id=0)
        {
            for(int i=0; i<4; i++)
            {
                cells[i] = Cell(X_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]%2), Y_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]/2), shape_id, data);
            }
        }

        void move_left()
        {
            for(int i=0; i<4; i++)
            {
                cells[i].set_position(cells[i].get_x() - (CELL_SIZE + 1), cells[i].get_y());
            }
        }
        void move_right()
        {
            for(int i=0; i<4; i++)
            {
                cells[i].set_position(cells[i].get_x() + (CELL_SIZE + 1), cells[i].get_y());
            }
        }
        void move_up()
        {
            for(int i=0; i<4; i++)
            {
                cells[i].set_position(cells[i].get_x(), cells[i].get_y()- (CELL_SIZE + 1));
            }
        }
        void move_down()
        {
            for(int i=0; i<4; i++)
            {
                cells[i].set_position(cells[i].get_x(), cells[i].get_y() + (CELL_SIZE + 1));
            }
        }
    };
}