//
// Created by anup on 8/12/23.
//

#ifndef SFML_TEST_MAINMENUSTATE_HPP
#define SFML_TEST_MAINMENUSTATE_HPP


#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"
namespace ttt
{
    class MainMenuState: public State
    {
    public:
        MainMenuState (GameDataRef data);
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _sprite;
        sf::Text _text;
        sf::Clock _clock;
        bool isHovered = false;

    };
}


#endif //SFML_TEST_MAINMENUSTATE_HPP
