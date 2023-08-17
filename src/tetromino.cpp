
#include "tetromino.hpp"
namespace tetris
{
        Cell::Cell(){}
    Cell::Cell(float x, float y, int shape_id, GameDataRef& data):_x(x), _y(y), _shape_id(shape_id), _data(data)
        {
            is_locked = false;
        }
        void Cell::set_sprite()
        {
            _cell_sprite.setTexture(_data->assets.getTexture("ColorBox"));
            _cell_sprite.setTextureRect(sf::IntRect (30 *(_shape_id),0,30,30));
            _cell_sprite.setPosition(_x, _y);
        }
        void Cell::draw()
        {
            _data->window.draw(_cell_sprite);
        }
        void Cell::set_position(float x, float y)
        {
            _x=x;
            _y=y;
            set_sprite();
        }
        float Cell::get_x()
        {
            return _x;
        }
        float Cell::get_y()
        {
            return _y;
        }
        int Cell::get_shape_id()
        {
            return _shape_id;
        }


Tetromino::Tetromino(GameDataRef& data, int shape_id): _shape_id(shape_id)
        {
            for(int i=0; i<4; i++)
            {
                cells[i] = Cell(X_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]%2), Y_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]/2), shape_id, data);
            }
            locked = false;
        }

        void Tetromino:: operator () (GameDataRef& data, int shape_id)
        {
            for(int i=0; i<4; i++)
            {
                cells[i] = Cell(X_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]%2), Y_SPAWN + (CELL_SIZE+1)*(shapes[shape_id][i]/2), shape_id, data);
            }
            locked = false;
        }
        bool Tetromino:: is_inside_grid(float x_increase, float y_increase)
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

        void Tetromino::move(float x_increase, float y_increase)
        {
            x_increase *= (CELL_SIZE+1);
            y_increase *= (CELL_SIZE+1);
            for(int i=0; i<4; i++)
            {
                cells[i].set_position(cells[i].get_x() + x_increase , cells[i].get_y() + y_increase);
            }
        }

        void Tetromino::move_left()
        {
            if (is_inside_grid(-1,0))
            {
                move(-1,0);
            }
        }
        void Tetromino:: move_right()
        {
            if (is_inside_grid(1,0))
            {
                move(1,0);
            }
        }
        void  Tetromino::move_up()
        {
            if (is_inside_grid(0,-1))
            {
                move(0,-1);
            }
        }
        void Tetromino::move_down()
        {
            if (is_inside_grid(0,1))
            {
                move(0,1);
            }
        }
        void Tetromino::set_locked(bool value)
        {
            locked = value;
        }
        int Tetromino::get_shape_id()
        {
            return _shape_id;
        }
        bool Tetromino::is_locked()
        {
            return locked;
        }

}