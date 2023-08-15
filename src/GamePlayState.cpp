#include "GamePlayState.hpp"
#include <iostream>

namespace tetris{

   void  GamePlayState::init()
    {
       for (int i=0; i<ROWS; i++)
       {
           for (int j=0; j<COLUMNS; j++)
           {
               grid[i][j] = 7;
           }
       }
        _data->assets.loadTexture("ColorBox", "../rec/ColorBox.png");
        _sprite_for_ColorBox.setTexture(_data->assets.getTexture("ColorBox"));
        cell.setTexture(_data->assets.getTexture("ColorBox"));


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
                 if (evt.key.code == sf::Keyboard::Space)
                 {
                     block.set_locked(true);
                 }
             }
         }
     }
    void  GamePlayState::update(float dt)
     {
        if(block.is_locked())
        {
            int id = block.get_shape_id();
            for (int i=0; i<4; i++)
            {
                int x_index, y_index;
                x_index = static_cast<int>((block.cells[i].get_x()-X_BOARD)/(CELL_SIZE+1));
                y_index = static_cast<int>((block.cells[i].get_y()-Y_BOARD)/(CELL_SIZE+1));
                grid[x_index][y_index] = id;
            }
            block(_data);
        }
     }
    void  GamePlayState::render(float dt)
     {


         _data->window.clear(sf::Color::Black);
         for(int i=0;i<10;i++)
         {
             for(int j=0;j<20;j++)
             {
                 cell.setTextureRect(sf::IntRect (CELL_SIZE *grid[i][j],0,CELL_SIZE,CELL_SIZE));
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