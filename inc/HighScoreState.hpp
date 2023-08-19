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
        HighScoreState ();
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

    private:
        long int highScore;
        long int topTen[10];
    };

}