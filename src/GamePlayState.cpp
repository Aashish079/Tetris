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
                    if(block.is_inside_grid(-1,0))
                    {

                        bool is_touching_other = false;
                        for (int i=0; i<4; i++)
                        {
                            int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE+1)) - 1;
                            int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE+1));
                            if (grid[x_index][y_index]!=7)
                            {
                                is_touching_other = true;
                                break;
                            }
                        }
                        if (!is_touching_other)
                        {
                            block.move_left();
                        }
                    }
                }
                if (evt.key.code == sf::Keyboard::Right)
                {
                    if(block.is_inside_grid(1,0))
                    {
                        bool is_touching_other = false;
                        for (int i=0; i<4; i++)
                        {
                            int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE+1)) + 1;
                            int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE+1));
                            if (grid[x_index][y_index]!=7)
                            {
                                is_touching_other = true;
                                break;
                            }
                        }
                        if (!is_touching_other)
                        {
                            block.move_right();
                        }
                    }
                }
                if (evt.key.code == sf::Keyboard::Up)
                {
                    if(block.is_inside_grid(0,-1))
                    {
                        bool is_touching_other = false;
                        for (int i=0; i<4; i++)
                        {
                            int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE+1));
                            int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE+1)) - 1;
                            if (grid[x_index][y_index]!=7)
                            {
                                is_touching_other = true;
                                break;
                            }
                        }
                        if (!is_touching_other)
                        {
                            block.move_up();
                        }
                    }
                }
                if (evt.key.code == sf::Keyboard::Down)
                {
                    if(block.is_inside_grid(0,1))
                    {
                        bool is_touching_other = false;
                        for (int i=0; i<4; i++)
                        {
                            int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE+1));
                            int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE+1)) + 1;
                            if (grid[x_index][y_index]!=7)
                            {
                                is_touching_other = true;
                                break;
                            }
                        }
                        if (!is_touching_other)
                        {
                            block.move_down();
                        }
                    }
                }
                if (evt.key.code == sf::Keyboard::Space)
                {
//                    block.set_locked(true);
                }
            }
        }
    }
    void  GamePlayState::update(float dt)
    {
        // filling id getting data into grid
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

            // clearing row
            for(int row =0 ; row<20;row++)
            {
                bool is_a_row_filled= true;
                for (int column =0 ;column<10;column++)
                {
                    if(grid[column][row]==7)
                    {
                        is_a_row_filled= false;
                        std::cout<<"The row is not filled"<<std::endl;
                        std::cout<<column<<" "<<is_a_row_filled<<std::endl;
                        break;
                    }
                }
                if(is_a_row_filled== true)
                {
                    if(row>0)
                    {
                        for(row;row>0;row--)
                        {
                            for (int column = 0; column < 10; column++)
                            {
                                grid[column][row] = grid[column ][row-1];
                                std::cout << "clearing row" << std::endl;
                            }
                        }
                    }
                    if(row==0)
                    {
                        for (int column = 0; column < 10; column++) {
                            grid[column][0] = 7;
                            std::cout << "clearing 1st row" << std::endl;
                        }
                    }

                }
            }

            block(_data, next_shape_id);
            next_block(_data, next_shape_id = generate_shape_id());
        }

        // timer

        time=_clock.getElapsedTime().asSeconds();
        _clock.restart();
        accumulated_time+=time;

        if(accumulated_time>delay)
        {
            // movedown
            if(block.is_inside_grid(0,1))
            {
                bool is_touching_other = false;
                for (int i=0; i<4; i++)
                {
                    int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE+1));
                    int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE+1)) + 1;
                    if (grid[x_index][y_index]!=7)
                    {
                        is_touching_other = true;
                        block.set_locked(true);
                        break;
                    }
                }
                if (!is_touching_other)
                {
                    block.move_down();
                }
            }
            else
            {
                block.set_locked(true);
            }

            accumulated_time=0;
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

        next_block.set_reference_position();
        for(int k=0; k<4; k++)
        {
            next_block.cells[k].set_sprite();
            next_block.cells[k].draw();
        }

        _data->window.display();
    }

    int GamePlayState::generate_shape_id()
    {
        std::random_device rd;  // Seed generator with a true random number from the system
        std::mt19937 generator(rd());  // Mersenne Twister engine

        // Define the range for random numbers
        std::uniform_int_distribution<int> distribution(0, 6);  // Range: [1, 100]

        // Generate and print random numbers
        int random_number = distribution(generator);
        return random_number;
    }
}