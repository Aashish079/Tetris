
#include <sstream>
#include "GameOverState.hpp"
#include "HighScoreState.hpp"
#include "MainMenuState.hpp"
#include "GamePlayState.hpp"
#include <iostream>
namespace tetris
{
    GameOverState::GameOverState(tetris::GameDataRef data, int score) : _data(data), score_value(score) {}

    void GameOverState::init()
    {
        // Show GameOver logo
        _data->assets.loadTexture("GameOver", "../rec/GameOver.png");
        _sprite.setTexture(_data->assets.getTexture("GameOver"));

        _sprite.setPosition(361, 50);

        // Show User's Score
        _data->assets.loadFont("Bebas", "../rec/Bebas-Regular.ttf");
        _score.setFont(_data->assets.getFont("Bebas"));
        _score.setString("Score: " + std::to_string(score_value));
        _score.setCharacterSize(30);
        _score.setFillColor(sf::Color::White);
        _score.setPosition(561,200);




        // Ask User information
        _label.setFont(_data->assets.getFont("Bebas"));
        _input_text.setFont(_data->assets.getFont("Bebas"));

        _label.setString("Enter your name:");
        _label.setCharacterSize(24);
        _label.setPosition(561, 400);

        inputBox.setPosition(561, 486);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(sf::Color::Black);

        _input_text.setCharacterSize(24);
        _input_text.setFillColor(sf::Color::Black);
        _input_text.setPosition(561, 486);

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
                if (evt.text.unicode == 32)
                { // Enter key
                    typing = false;
                    // Clear the input field
                    fileManager.storeScore(playerName, score_value);
                    _data->machine.addState(StateRef(new MainMenuState(_data)), true);
                }
                if (evt.text.unicode == 8 && !playerName.empty())
                { // Backspace
                    playerName.pop_back();
                }
                if (evt.text.unicode >= 32 && evt.text.unicode <= 126)
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
        _data->window.draw(_score);
        //         _data->window.draw(_text);

        _data->window.display();
    }
}