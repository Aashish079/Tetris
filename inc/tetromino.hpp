#pragma once

#include "SFML/Graphics.hpp"
#include "globals.hpp"
#include "game.hpp"

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
        Cell();
        Cell(float x, float y, int shape_id, GameDataRef& data);

        void set_sprite();
        void draw();

        void set_position(float x, float y);

        float get_x();

        float get_y();

        int get_shape_id();

    };
    class Tetromino
    {
    private:
        bool locked;
        int _shape_id;

    public:
        GameDataRef _data;
        Cell cells[4];
        Tetromino(){}
        Tetromino(GameDataRef& data, int shape_id);

        void operator () (GameDataRef& data, int shape_id);

        void set_reference_position();

        bool is_inside_grid(float x_increase, float y_increase);


        void move(float x_increase, float y_increase);


        void move_left();

        void move_right();

        void move_up();

        void move_down();

        void set_locked(bool value);

        int get_shape_id();

        bool is_locked();

    };
}