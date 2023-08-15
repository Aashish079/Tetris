#include "GamePlayState.hpp"
#include <iostream>

namespace tetris{

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
             else if (sf::Event::KeyPressed == evt.type)
             {
                 if (evt.key.code == sf::Keyboard::Left)
                 {
                     block.move_left();
                 }
                 if (evt.key.code == sf::Keyboard::Right)
                 {
                     block.move_right();
                 }
                 if (evt.key.code == sf::Keyboard::Up)
                 {
                     block.move_up();
                 }
                 if (evt.key.code == sf::Keyboard::Down)
                 {
                     block.move_down();
                 }
             }
         }
     }
    void  GamePlayState::update(float dt)
     {

     }
    void  GamePlayState::render(float dt)
     {
         sf::RectangleShape cell (sf::Vector2f(CELL_SIZE,CELL_SIZE));
         cell.setFillColor(sf::Color(0,100,100,100));
         _data->window.clear(sf::Color::Black);
         for(int i=0;i<10;i++)
         {
             for(int j=0;j<20;j++)
             {
                 cell.setPosition(((i+15) * (CELL_SIZE+1)) , ((j+1) * (CELL_SIZE+1)) );
                 _data->window.draw(cell);
             }
         }
         for(int k=0; k<4; k++)
         {
             block.cells[k].set_sprite();
             block.cells[k].draw();
         }
         _data->window.display();
     }

}