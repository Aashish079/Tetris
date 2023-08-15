#include "GamePlayState.hpp"
#include <iostream>

namespace tetris{

   void  GamePlayState::init()
    {
        _data->assets.loadTexture("ColorBox", "../rec/ColorBox.png");
        _sprite_for_ColorBox.setTexture(_data->assets.getTexture("ColorBox"));
        cell.setTexture(_data->assets.getTexture("ColorBox"));
        cell.setTextureRect(sf::IntRect (30 *7,0,30,30));

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


         _data->window.clear(sf::Color::Black);
         for(int i=0;i<10;i++)
         {
             for(int j=0;j<20;j++)
             {
                 cell.setPosition(((i+17) * (CELL_SIZE+1)) , ((j+1) * (CELL_SIZE+1)) );
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