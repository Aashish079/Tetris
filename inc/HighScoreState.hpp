#pragma once

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "tetromino.hpp"
#include "random"
#include "FileManager.hpp"
#include <sstream>
#include "Intro_State.hpp"
#include "MainMenuState.hpp"


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

    private:

         GameDataRef _data;
        FileManager fileManager;
        std::vector<std::pair<std::string, int >> playerScore;
        sf::Sprite _sprite;
        sf::Text _text, name, score;
        sf::Clock _clock;
        std::string playerName;

        sf::RectangleShape inputBox;
    };

}