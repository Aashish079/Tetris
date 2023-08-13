#include "GamePlayState.hpp"
#include <iostream>

namespace ttt{
    GamePlayState::GamePlayState(ttt::GameDataRef data) : _data(data){}

   void  GamePlayState::init()
    {
        _data->assets.loadTexture("ColorBox", "/home/anup/CLionProjects/Tetris/rec/ColorBox.png");
        _sprite_for_ColorBox.setTexture(_data->assets.getTexture("ColorBox"));

    }

    void  GamePlayState:: handleInput()
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
    void  GamePlayState::update(float dt)
     {

     }
    void  GamePlayState::render(float dt)
     {

        sf::RectangleShape cell (sf::Vector2f(30,30));
        cell.setFillColor(sf::Color(0,100,100,100));
         _data->window.clear(sf::Color::Black);
         for(int i=0;i<10;i++)
         {
             for(int j=0;j<20;j++)
             {
                 cell.setPosition(((i+15) * 31) , ((j+1) * 31) );
                 _sprite_for_ColorBox.setTextureRect(sf::IntRect (30 *(j%7),0,30,30));

                 _data->window.draw(cell);
                 _sprite_for_ColorBox.setPosition(((i+15) * 31),((j+1) * 31) );
//                 _data->window.draw(_sprite_for_ColorBox);
             }
         }


        _data->window.display();
     }
}