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

        _data->assets.loadFont("Bebas", "../rec/Bebas-Regular.ttf");
        _label.setFont(_data->assets.getFont("Bebas"));
        _input_text.setFont(_data->assets.getFont("Bebas"));

        _label.setString("Enter your name:");
        _label.setCharacterSize(24);
        _label.setPosition(478, 100);

        inputBox.setPosition(478, 186);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(sf::Color::Black);

        _input_text.setCharacterSize(24);
        _input_text.setFillColor(sf::Color::Black);
        _input_text.setPosition(478, 186);

        inputBox.setSize(sf::Vector2f(300, 40));

        
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
            // Input Field for Player Name
             if (evt.type == sf::Event::TextEntered && typing) {
                if (evt.text.unicode == 13) { // Enter key
                    typing = false;
                    // Clear the input field
                    _input_text.setString("");
                } else if (evt.text.unicode == 8 && !playerName.empty()) { // Backspace
                    playerName.pop_back();
                } else if (evt.text.unicode >= 32 && evt.text.unicode <= 126) {
                    playerName += static_cast<char>(evt.text.unicode);
                }
                _input_text.setString(playerName);
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
        _data->window.draw(_label);
        _data->window.draw(inputBox);
        _data->window.draw(_input_text);
        //         _data->window.draw(_text);

        _data->window.display();
    }
}