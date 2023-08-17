#pragma once

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "tetromino.hpp"



namespace tetris
{
    class GamePlayState: public State
    {
    public:
        GamePlayState (GameDataRef data):_data(data), block(data){};
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

        int grid[10][20];
    private:
        GameDataRef _data;


        sf::Sprite _sprite_for_ColorBox ,cell;
        sf::Text _text;
        sf::Clock _clock;

        Tetromino block;

        float time, accumulated_time =0,delay=0.5;
    };

}