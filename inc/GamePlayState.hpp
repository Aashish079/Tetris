#pragma once

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"
#include "Global.hpp"

namespace tetris
{
    class GamePlayState: public State
    {
    public:
        GamePlayState (GameDataRef data);
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _sprite_for_ColorBox;
        sf::Text _text;
        sf::Clock _clock;
        int ShapeMatrix[7][4] =
                {
                        1,3,5,7, // I
                        2,4,5,7, // Z
                        3,5,4,6, // S
                        3,5,4,7, // T
                        2,3,5,7, // L
                        3,5,7,6, // J
                        2,3,4,5, // O
                };
        int x_postion_of_tetromino=0,y_postion_of_tetromino=0;

        sf::RectangleShape cell;

        float accumulate_time=0, delay=0.3;



    };
}