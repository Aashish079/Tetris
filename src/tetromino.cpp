
#include "tetromino.hpp"
namespace tetris
{
    Cell::Cell() {}
    Cell::Cell(float x, float y, int shape_id, GameDataRef &data) : _x(x), _y(y), _shape_id(shape_id), _data(data)
    {
        is_locked = false;
    }
    void Cell::set_sprite()
    {
        _cell_sprite.setTexture(_data->assets.getTexture("ColorBox"));
        _cell_sprite.setTextureRect(sf::IntRect(30 * (_shape_id), 0, 30, 30));
        _cell_sprite.setPosition(_x, _y);
    }
    void Cell::draw()
    {
        _data->window.draw(_cell_sprite);
    }
    void Cell::set_position(float x, float y)
    {
        _x = x;
        _y = y;
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

    Tetromino::Tetromino(GameDataRef &data, int shape_id)
    {
        _data = data;
        _shape_id = shape_id;
        locked = false;
        for (int i = 0; i < 4; i++)
        {
            if (shape_id != 0)
                cells[i] = Cell(X_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] % 2), Y_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] / 2 - 1), _shape_id, _data);
            else
                cells[i] = Cell(X_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] % 2), Y_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] / 2), _shape_id, _data);
        }
    }

    void Tetromino::operator()(GameDataRef &data, int shape_id)
    {
        _data = data;
        _shape_id = shape_id;
        locked = false;
        for (int i = 0; i < 4; i++)
        {
            if (shape_id != 0)
                cells[i] = Cell(X_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] % 2), Y_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] / 2 - 1), _shape_id, _data);
            else
                cells[i] = Cell(X_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] % 2), Y_SPAWN + (CELL_SIZE + 1) * (shapes[_shape_id][i] / 2), _shape_id, _data);

        }
    }

    void Tetromino::set_reference_position()
    {
        locked = true;
        for (int i = 0; i < 4; i++)
        {
            cells[i] = Cell(X_NEXT_BLOCK + (CELL_SIZE + 1) * (shapes[_shape_id][i] % 2), Y_NEXT_BLOCK + (CELL_SIZE + 1) * (shapes[_shape_id][i] / 2), _shape_id, _data);
        }
    }

    bool Tetromino::is_inside_grid(float x_increase, float y_increase)
    {
        bool result = true;
        x_increase *= (CELL_SIZE + 1);
        y_increase *= (CELL_SIZE + 1);
        for (int i = 0; i < 4; i++)
        {
            if (!((cells[i].get_x() + x_increase >= X_BOARD) && (cells[i].get_x() + x_increase < X_BOARD + 10 * (CELL_SIZE + 1)) && (cells[i].get_y() + y_increase >= Y_BOARD) && (cells[i].get_y() + y_increase < Y_BOARD + 20 * (CELL_SIZE + 1))))
            {
                result = false;
                break;
            }
        }
        return result;
    }

    void Tetromino::move(float x_increase, float y_increase)
    {
        x_increase *= (CELL_SIZE + 1);
        y_increase *= (CELL_SIZE + 1);
        for (int i = 0; i < 4; i++)
        {
            cells[i].set_position(cells[i].get_x() + x_increase, cells[i].get_y() + y_increase);
        }
    }

    void Tetromino::move_left()
    {
        if (is_inside_grid(-1, 0))
        {
            move(-1, 0);
        }
    }
    void Tetromino::move_right()
    {
        if (is_inside_grid(1, 0))
        {
            move(1, 0);
        }
    }
    void Tetromino::move_up()
    {
        if (is_inside_grid(0, -1))
        {
            move(0, -1);
        }
    }
    void Tetromino::move_down()
    {
        if (is_inside_grid(0, 1))
        {
            move(0, 1);
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

    float Tetromino::get_rotated_x(Cell c)
    {
        float x_ref = cells[1].get_x();
        float y_ref = cells[1].get_y();
        float x_rotated = x_ref + c.get_y() - y_ref;
        return x_rotated;
    }
    float Tetromino::get_rotated_y(Cell c)
    {
        float x_ref = cells[1].get_x();
        float y_ref = cells[1].get_y();
        float y_rotated = y_ref - c.get_x() + x_ref;
        return y_rotated;
    }

    void Tetromino::calc_extreme_x_pos()
    {
        x_largest = cells[0].get_x();
        x_smallest = cells[0].get_x();
        for (int i = 1; i < 4; i++)
        {
            if (x_largest < cells[i].get_x())
                x_largest = cells[i].get_x();
            if (x_smallest > cells[i].get_x())
                x_smallest = cells[i].get_x();
        }
    }
}