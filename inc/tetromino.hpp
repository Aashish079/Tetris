#pragma once

#include "SFML/Graphics.hpp"
#include "globals.hpp"

namespace tetris
{
    class Cell
    {
    private:
        float _x, _y;
        int _shape_id;
        GameDataRef _data;
        sf::Sprite _cell_sprite;
        bool is_locked;
    public:
        Cell(){}
        Cell(float x, float y, int shape_id, GameDataRef& data):_x(x), _y(y), _shape_id(shape_id), _data(data)
        {
            is_locked = false;
        }
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
        int get_shape_id()
        {
            return _shape_id;
        }
    };
    class Tetromino
    {
    private:
        bool locked;
        int _shape_id;

    public:
        Cell cells[4];

        Tetromino(GameDataRef& data, int shape_id=2): _shape_id(shape_id)
        {
            for(int i=0; i<4; i++)
            {
                cells[i] = Cell(X_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]%2), Y_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]/2), shape_id, data);
            }
            locked = false;
        }

        void operator () (GameDataRef& data, int shape_id=2)
        {
            for(int i=0; i<4; i++)
            {
                cells[i] = Cell(X_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]%2), Y_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]/2), shape_id, data);
            }
            locked = false;
        }
        bool is_touching_other(int x_increase, int y_increase)
        {
            bool result = false;
            for(int i=0; i<4; i++)
            {
                int x_index, y_index;

            }
        }
        bool is_inside_grid(float x_increase, float y_increase)
        {
            bool result= true;
            x_increase *= (CELL_SIZE+1);
            y_increase *= (CELL_SIZE+1);
            for (int i=0; i<4; i++)
            {
                if (!((cells[i].get_x() + x_increase >= X_BOARD) && (cells[i].get_x() + x_increase < X_BOARD + 10*(CELL_SIZE+1)) && (cells[i].get_y() + y_increase >= Y_BOARD) && (cells[i].get_y() + y_increase < Y_BOARD + 20*(CELL_SIZE+1))))
                {
                    result = false;
                    break;
                }
            }
            return result;
        }

        void move(float x_increase, float y_increase)
        {
            x_increase *= (CELL_SIZE+1);
            y_increase *= (CELL_SIZE+1);
            for(int i=0; i<4; i++)
            {
                cells[i].set_position(cells[i].get_x() + x_increase , cells[i].get_y() + y_increase);
            }
        }

        void move_left()
        {
            if (is_inside_grid(-1,0))
            {
                move(-1,0);
            }
        }
        void move_right()
        {
            if (is_inside_grid(1,0))
            {
                move(1,0);
            }
        }
        void move_up()
        {
            if (is_inside_grid(0,-1))
            {
                move(0,-1);
            }
        }
        void move_down()
        {
            if (is_inside_grid(0,1))
            {
                move(0,1);
            }
        }
        void set_locked(bool value)
        {
            locked = value;
        }
        int get_shape_id()
        {
            return _shape_id;
        }
        bool is_locked()
        {
            return locked;
        }
    };
}