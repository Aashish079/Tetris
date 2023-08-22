
#include <sstream>
#include "GameOverState.hpp"
#include "HighScoreState.hpp"
#include "GamePlayState.hpp"
namespace tetris
{
    GameOverState::GameOverState(tetris::GameDataRef data) : _data(data) {}

    void GameOverState::init()
    {
        _data->assets.loadTexture("GameOver", "../rec/GAMEOVER.png");

        _sprite.setTexture(_data->assets.getTexture("GameOver"));

        _sprite.setPosition(361, 50);

        _data->assets.loadFont("Bebas", "../rec/Bebas-Regular.ttf");
        _label.setFont(_data->assets.getFont("Bebas"));
        _input_text.setFont(_data->assets.getFont("Bebas"));

        _label.setString("Enter your name:");
        _label.setCharacterSize(24);
        _label.setPosition(461, 200);

        inputBox.setPosition(461, 286);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(sf::Color::Black);

        _input_text.setCharacterSize(24);
        _input_text.setFillColor(sf::Color::Black);
        _input_text.setPosition(461, 286);

        inputBox.setSize(sf::Vector2f(300, 40));
    }

    void GameOverState::handleInput()
    {
        sf::Event evt;
        while (_data->window.pollEvent(evt))
        {
            if (sf::Event::Closed == evt.type)
            {
                _data->window.close();
            }
            // Input Field for Player Name
            if (evt.type == sf::Event::TextEntered && typing)
            {
                if (evt.text.unicode == 13)
                { // Enter key
                    typing = false;
                    // Clear the input field
                    _input_text.setString("");
                }
                else if (evt.text.unicode == 8 && !playerName.empty())
                { // Backspace
                    playerName.pop_back();
                }
                else if (evt.text.unicode >= 32 && evt.text.unicode <= 126)
                {
                    playerName += static_cast<char>(evt.text.unicode);
                }
                _input_text.setString(playerName);
            }
        }
    }
    void GameOverState::update(float dt)
    {
        // if (_clock.getElapsedTime().asSeconds() > 4)
        // {
        //     // Switch To Main Menu
        //     _data->machine.addState(StateRef(new MainMenuState(_data)), true);
        // }
    }
    void GameOverState::render(float dt)
    {

         _data->window.clear(sf::Color::Black);
        _data->window.draw(_sprite);
        _data->window.draw(_label);
        _data->window.draw(inputBox);
        _data->window.draw(_input_text);
        //         _data->window.draw(_text);

        _data->window.display();
    }
}