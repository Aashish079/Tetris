//
// Created by anup on 8/12/23.
//
#include <iostream>
#include "MainMenuState.hpp"
#include "GamePlayState.hpp"

namespace ttt
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

    void MainMenuState::init()
    {
        _data->assets.loadTexture("PlayButton", "/home/anup/CLionProjects/Tetris/rec/PlayButton.png");
        _data->assets.loadTexture("HighScoreButton", "/home/anup/CLionProjects/Tetris/rec/HighScoreButton.png");
        _data->assets.loadTexture("ExitButton", "/home/anup/CLionProjects/Tetris/rec/ExitButton.png");

        _sprite_for_PlayButton.setTexture(_data->assets.getTexture("PlayButton"));
        _sprite_for_PlayButton.setPosition(383,191);

        _sprite_for_HighScoreButton.setTexture(_data->assets.getTexture("HighScoreButton"));
        _sprite_for_HighScoreButton.setPosition(383,321);

        _sprite_for_ExitButton.setTexture(_data->assets.getTexture("ExitButton"));
        _sprite_for_ExitButton.setPosition(383,451);
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

            if(_data->input.IsSpriteClicked(_sprite_for_PlayButton, sf::Mouse::Left, _data->window))
            {
                std::cout<<"go to GamePlay"<<std::endl;
                _data->machine.addState(StateRef(new GamePlayState(_data)), true);
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