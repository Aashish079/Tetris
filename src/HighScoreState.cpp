
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
        playerScore = fileManager.GetSortedScore();


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


    void HighScoreState::render(float dt)
    {

        int i = 0;
        _data->window.clear(sf::Color::Black);

        for (const std::pair<std::string, int>& player : playerScore)
        {
            name.setString(std::to_string(i+1) + ". "+player.first);
            name.setFont(_data->assets.getFont("Bebas"));
            name.setFillColor(sf::Color::White);
            name.setCharacterSize(48);
            name.setPosition(500, 150 + i * 50);

            score.setString(std::to_string(  player.second));
            score.setFont(_data->assets.getFont("Bebas"));
            score.setCharacterSize(48);
            score.setPosition(800, 150 + i * 50);

            
             score.setString(std::to_string(player.second));
//             std::cout << "Key1: " << player.first << ", Value1: " << player.second << std::endl;



            _data->window.draw(name);
            _data->window.draw(score);
            if(i==9 )
                break;
            i++;
        }

        _data->window.draw(_sprite);
        _data->window.display();
    }
} // namespace tetris