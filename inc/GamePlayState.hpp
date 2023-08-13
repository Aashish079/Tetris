#pragma once

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

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


    };
}