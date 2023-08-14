#include "GamePlayState.hpp"
#include <iostream>

namespace tetris{
    GamePlayState::GamePlayState(tetris::GameDataRef data) : _data(data){}

   void  GamePlayState::init()
    {
        _data->assets.loadTexture("ColorBox", "../rec/ColorBox.png");
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
             if (evt.type == sf::Event::KeyPressed)
             {
                 if (evt.key.code == sf::Keyboard::Left)
                 {
                    x_postion_of_tetromino--;
                 }
                 if (evt.key.code == sf::Keyboard::Right)
                 {
                     x_postion_of_tetromino++;
                 }
                 if (evt.key.code == sf::Keyboard::Up)
                 {
                     y_postion_of_tetromino--;
                 }
                 if (evt.key.code == sf::Keyboard::Down)
                 {
                     y_postion_of_tetromino++;
                 }
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
                 cell.setPosition(((i+17) * 31) , ((j+1) * 31) );

                 _data->window.draw(cell);

             }
         }

         for(int k =0 ; k<4;k++)
         {
             _sprite_for_ColorBox.setTextureRect(sf::IntRect (30 *(0),0,30,30));
             _sprite_for_ColorBox.setPosition(((x_postion_of_tetromino) * 31)+(ShapeMatrix[0][k]%2)*31,((y_postion_of_tetromino) * 31)+(ShapeMatrix[0][k]/2)*31 );
             _data->window.draw(_sprite_for_ColorBox);
         }


        _data->window.display();
     }
}