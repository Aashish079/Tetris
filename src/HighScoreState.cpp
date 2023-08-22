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
        _data->assets.loadTexture("HighScore", "../rec/HighScores.png");

        _sprite.setTexture(_data->assets.getTexture("HighScore"));

        _sprite.setPosition(361, 50);

        _data->assets.loadFont("Bebas", "../rec/Bebas-Regular.ttf");
        _text.setFont(_data->assets.getFont("Bebas"));

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
            // Go to main menu is escape is pressed
            if (evt.text.unicode == 8)
            { // Backspace key
                _data->machine.addState(StateRef(new MainMenuState(_data)), true);
                // Clear the input field
            }
        }

    }
    void HighScoreState::update(float dt){

    }

    void HighScoreState::storeScore(){
    }

        void HighScoreState::render(float dt)
        {
            _data->window.clear(sf::Color::Black);
            _data->window.draw(_sprite);
            _data->window.display();
        }
} // namespace tetris