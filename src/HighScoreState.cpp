#include <sstream>
#include "Intro_State.hpp"
#include "MainMenuState.hpp"
#include "GamePlayState.hpp"
#include "HighScoreState.hpp"
namespace tetris
{
    HighScoreState::HighScoreState(tetris::GameDataRef data) : _data(data) {}

    void HighScoreState::init()
    {
        _data->assets.loadTexture("IntroPage", "../rec/IntroPage.jpg");

        _sprite.setTexture(_data->assets.getTexture("IntroPage"));
    }

    void HighScoreState::handleInput()
    {
        sf::Event evt;
        while (_data->window.pollEvent(evt))
        {
            if (sf::Event::Closed == evt.type)
            {
                _data->window.close();
            }
        }
    }

    void HighScoreState::update(float dt)
    {
        // if (_clock.getElapsedTime().asSeconds() > 2)
        // {
        //     // Switch To Main Menu
        //     _data->machine.addState(StateRef(new MainMenuState(_data)), true);
        //     //             _data->machine.addState(StateRef(new GamePlayState(_data)), true);
        // }
    }
    void HighScoreState::render(float dt)
    {

        _data->window.clear(sf::Color::Red);
        _data->window.draw(_sprite);
        //         _data->window.draw(_text);

        _data->window.display();
    }
}