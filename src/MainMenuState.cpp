//
// Created by anup on 8/12/23.
//
#include "MainMenuState.hpp"

namespace ttt {
    MainMenuState::MainMenuState(ttt::GameDataRef data) : _data(data) {}

    void MainMenuState::init() {
        _data->assets.loadTexture("PlayButton", "/home/anup/CLionProjects/sfml-test/rec/PlayButton.png");

        _sprite.setTexture(_data->assets.getTexture("PlayButton"));
        _sprite.setPosition(533,322);

    }

    void MainMenuState::handleInput() {
        sf::Event evt;
        while (_data->window.pollEvent(evt)) {
            if (sf::Event::Closed == evt.type) {
                _data->window.close();
            }

            sf::Vector2i mousePosition = sf::Mouse::getPosition(_data->window);
            sf::FloatRect spriteBounds = _sprite.getGlobalBounds();

            if (spriteBounds.contains(mousePosition.x, mousePosition.y))
            {
                if (!isHovered)
                {
                    // Mouse entered the sprite

                    isHovered = true;

                    // Update sprite appearance when hovered
                    // For example, you can change the sprite's color
                    _sprite.setColor(sf::Color(100, 200, 200));
                }
            }
            else
            {
                if (isHovered)
                {
                    // Mouse left the sprite
                    isHovered = false;
                    // Reset sprite appearance
                    _sprite.setColor(sf::Color::White);
                }
            }


        }
    }



    void MainMenuState::update(float dt) {



    }
    void MainMenuState::render(float dt) {

        _data->window.clear(sf::Color::Black);
        _data->window.draw(_sprite);
//         _data->window.draw(_text);

        _data->window.display();
    }
}