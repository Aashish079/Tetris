
#ifndef SFML_TEST_INTRO_STATE_HPP
#define SFML_TEST_INTRO_STATE_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game.hpp"

namespace tetris
{
    class IntroState : public State
    {
    public:
        IntroState(GameDataRef data);
        void init();

        void handleInput();
        void update(float dt);
        void render(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _sprite;
        sf::Text _text;
        sf::Clock _clock;
    };
}

#endif // SFML_TEST_INTRO_STATE_HPP
