#pragma once

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "tetromino.hpp"
#include "random"


namespace tetris
{
    class HighScoreState: public State
    {
    public:
        HighScoreState(GameDataRef data);
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);
        void storeScore();

    private:
        long int highScore;
        long int topTen[10];
         GameDataRef _data;

        sf::Sprite _sprite;
        sf::Text _text;
        sf::Clock _clock;
        std::string playerName;

        sf::RectangleShape inputBox;
    };

}