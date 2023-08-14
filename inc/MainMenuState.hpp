//
// Created by anup on 8/12/23.
//


#ifndef SFML_TEST_MAINMENUSTATE_HPP
#define SFML_TEST_MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

namespace tetris
{
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data);

        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _sprite_for_PlayButton, _sprite_for_HighScoreButton, _sprite_for_ExitButton;
        sf::Text _text;
        sf::Clock _clock;
        bool isHovered = false;




    };



};


#endif // SFML_TEST_MAINMENUSTATE_HPP
