//
// Created by anup on 8/12/23.
//
#include <iostream>
#include "MainMenuState.hpp"
#include "GamePlayState.hpp"
#include "HighScoreState.hpp"

namespace tetris
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

    void MainMenuState::init()
    {
        _data->assets.loadTexture("PlayButton", "../rec/PlayButton.png");
        _data->assets.loadTexture("HighScoreButton", "../rec/HighScoreButton.png");
        _data->assets.loadTexture("ExitButton", "../rec/ExitButton.png");

        _sprite_for_PlayButton.setTexture(_data->assets.getTexture("PlayButton"));
        _sprite_for_PlayButton.setPosition(383, 191);

        _sprite_for_HighScoreButton.setTexture(_data->assets.getTexture("HighScoreButton"));
        _sprite_for_HighScoreButton.setPosition(383, 321);

        _sprite_for_ExitButton.setTexture(_data->assets.getTexture("ExitButton"));
        _sprite_for_ExitButton.setPosition(383, 451);
    }

    void MainMenuState::handleInput()
    {
        sf::Event evt;
        while (_data->window.pollEvent(evt))
        {
            if (sf::Event::Closed == evt.type)
            {
                _data->window.close();
            }

            sf::Vector2i mousePosition = sf::Mouse::getPosition(_data->window);
            sf::FloatRect spriteBounds = _sprite_for_PlayButton.getGlobalBounds();

            if (spriteBounds.contains(mousePosition.x, mousePosition.y))
            {
                if (!isHovered)
                {
                    // Mouse entered the sprite

                    isHovered = true;

                    // Update sprite appearance when hovered
                    // For example, you can change the sprite's color
                    _sprite_for_PlayButton.setColor(sf::Color(100, 200, 200));
                }
            }
            else
            {
                if (isHovered)
                {
                    // Mouse left the sprite
                    isHovered = false;
                    // Reset sprite appearance
                    _sprite_for_PlayButton.setColor(sf::Color::White);
                }
            }

            // Hover for Highscore button
            sf::Vector2i mousePosition2 = sf::Mouse::getPosition(_data->window);
            sf::FloatRect spriteBounds2 = _sprite_for_HighScoreButton.getGlobalBounds();

            if (spriteBounds2.contains(mousePosition2.x, mousePosition2.y))
            {
                if (!isHovered2)
                {
                    // Mouse entered the sprite

                    isHovered2 = true;

                    // Update sprite appearance when hovered
                    // For example, you can change the sprite's color
                    _sprite_for_HighScoreButton.setColor(sf::Color(100, 200, 200));
                }
            }
            else
            {
                if (isHovered2)
                {
                    // Mouse left the sprite
                    isHovered2 = false;
                    // Reset sprite appearance
                    _sprite_for_HighScoreButton.setColor(sf::Color::White);
                }
            }

            // Hover effect for Exit button
            sf::Vector2i mousePosition3 = sf::Mouse::getPosition(_data->window);
            sf::FloatRect spriteBounds3 = _sprite_for_ExitButton.getGlobalBounds();

            if (spriteBounds3.contains(mousePosition3.x, mousePosition3.y))
            {
                if (!isHovered3)
                {
                    // Mouse entered the sprite

                    isHovered3 = true;

                    // Update sprite appearance when hovered
                    // For example, you can change the sprite's color
                    _sprite_for_ExitButton.setColor(sf::Color(100, 200, 200));
                }
            }
            else
            {
                if (isHovered3)
                {
                    // Mouse left the sprite
                    isHovered3 = false;
                    // Reset sprite appearance
                    _sprite_for_ExitButton.setColor(sf::Color::White);
                }
            }

            if (_data->input.IsSpriteClicked(_sprite_for_PlayButton, sf::Mouse::Left, _data->window))
            {
                std::cout << "go to GamePlay" << std::endl;
                _data->machine.addState(StateRef(new GamePlayState(_data)), true);
                //                _data->machine.addState(StateRef(new MainMenuState(_data)), true);
            }

            if (_data->input.IsSpriteClicked(_sprite_for_HighScoreButton, sf::Mouse::Left, _data->window))
            {
                std::cout << "go to Highscore" << std::endl;
                _data->machine.addState(StateRef(new HighScoreState(_data)), true);
                //                _data->machine.addState(StateRef(new MainMenuState(_data)), true);
            }

        }
    }

    void MainMenuState::update(float dt)
    {
    }
    void MainMenuState::render(float dt)
    {

        _data->window.clear(sf::Color::Black);
        _data->window.draw(_sprite_for_PlayButton);
        _data->window.draw(_sprite_for_HighScoreButton);
        _data->window.draw(_sprite_for_ExitButton);

        //         _data->window.draw(_text);

        _data->window.display();
    }
}