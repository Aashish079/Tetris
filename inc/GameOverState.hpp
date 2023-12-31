#pragma once

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"
#include "globals.hpp"
#include "tetromino.hpp"
#include "random"
#include "FileManager.hpp"

namespace tetris
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef data, int score);
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _sprite;
        sf::Text _text, _label, _input_text, _score;
        sf::Clock _clock;
        bool typing = true;
        std::string playerName;
        int score_value;
        sf::RectangleShape inputBox;

        FileManager fileManager;
    };
}