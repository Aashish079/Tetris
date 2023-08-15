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

    private:
        GameDataRef _data;

        sf::Sprite _sprite_for_ColorBox ,cell;
        sf::Text _text;
        sf::Clock _clock;

        int grid[10][20];
        Tetromino block;
    };

}