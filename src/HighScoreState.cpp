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
        name.setFont(_data->assets.getFont("Bebas"));
        score.setFont(_data->assets.getFont("Bebas"));
        fileManager.getScoreFromFile();
        playerScore = fileManager.getPlayerScore();
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
    void HighScoreState::update(float dt)
    {
    }

    void HighScoreState::storeScore()
    {
    }

    void HighScoreState::render(float dt)
    {
        // Get an iterator pointing to the first element in the map
        std::map<std::string, int>::iterator it = playerScore.begin();

        // Iterate through the map and print the elements
        int i = 0;
        while (it != playerScore.end())
        {
            name.setString(it->first);
            name.setFont(_data->assets.getFont("Bebas"));
            name.setCharacterSize(24);
            name.setPosition(561, 200 + i * 50);

            score.setString(std::to_string(it->second));
            score.setFont(_data->assets.getFont("Bebas"));
            score.setCharacterSize(24);
            score.setPosition(861, 200 + i * 50);

            
            // score.setString(it->second);
            // std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
            i++;
            ++it;
        }
         _data->window.draw(name);
            _data->window.draw(score);
        _data->window.clear(sf::Color::Black);
        _data->window.draw(_sprite);
        _data->window.display();
    }
} // namespace tetris