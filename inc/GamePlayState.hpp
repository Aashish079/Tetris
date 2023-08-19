#pragma once

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "tetromino.hpp"
#include "random"


namespace tetris
{
    class GamePlayState: public State
    {
    public:
        GamePlayState (GameDataRef data):_data(data),block(_data, current_shape_id = generate_shape_id()), next_block(_data, next_shape_id = generate_shape_id()){};
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

        int generate_shape_id();
        void calc_rotated_pts();
        void rotate();

        int grid[10][20];
        float x_rotated_pts[4], y_rotated_pts[4];
    private:
        GameDataRef _data;


        sf::Sprite _sprite_for_ColorBox ,cell, _NextTetrominoFrame, _GridFrame;
        sf::Text _text;
        sf::Clock _clock;

        Tetromino block, next_block;
        int current_shape_id, next_shape_id;

        float time, accumulated_time =0,delay=0.5;
    };

}