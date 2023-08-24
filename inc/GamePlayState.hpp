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


        sf::Sprite _sprite_for_ColorBox ,cell, _NextTetrominoFrame, _GridFrame, _GameOver;
        sf::Text _score;
        sf::Clock _clock;
        sf::Sound _clear_sound;

        Tetromino block, next_block;
        int current_shape_id, next_shape_id;
        int score_value = 0;
        bool is_game_over = false;
        float time, accumulated_time =0,delay=0.5;

        
    };

}