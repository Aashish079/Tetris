#include "GamePlayState.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace tetris
{
    void GamePlayState::init()
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                grid[i][j] = 7;
            }
        }
        _data->assets.loadTexture("ColorBox", "../rec/ColorBox.png");
        _data->assets.loadTexture("GameOver", "../rec/GameOver.png");
        _sprite_for_ColorBox.setTexture(_data->assets.getTexture("ColorBox"));
        cell.setTexture(_data->assets.getTexture("ColorBox"));
        
        _GameOver.setTexture(_data->assets.getTexture("GameOver"));

        _data->assets.loadTexture("NextTetrominoFrame", "../rec/NextTetrominoFrame.png");
        _NextTetrominoFrame.setTexture(_data->assets.getTexture("NextTetrominoFrame"));
        _NextTetrominoFrame.setPosition(X_NEXT_BLOCK - 31, Y_NEXT_BLOCK - 31);

        _data->assets.loadTexture("GridFrame", "../rec/GridFrame.png");
        _GridFrame.setTexture(_data->assets.getTexture("GridFrame"));
        _GridFrame.setPosition(X_BOARD - 3, Y_BOARD - 3); // 3 is subtracted of stroke

        _data->assets.loadFont("Bebas", "../rec/Bebas-Regular.ttf");
        _score.setFont(_data->assets.getFont("Bebas"));


        _data->assets.loadBuffer("ClearSound","../rec/ClearSound.wav");
        _clear_sound.setBuffer(_data->assets.getBuffer("ClearSound"));

        _data->assets.loadBuffer("MoveDownSound","../rec/MoveDownSound.wav");
        _move_down_sound.setBuffer(_data->assets.getBuffer("MoveDownSound"));

        _data->assets.loadBuffer("MoveUpSound","../rec/MoveUpSound.wav");
        _move_up_sound.setBuffer(_data->assets.getBuffer("MoveUpSound"));

        _data->assets.loadBuffer("MoveLeftRightSound","../rec/MoveDownSound.wav");
        _move_left_right_sound.setBuffer(_data->assets.getBuffer("MoveLeftRightSound"));

        _data->assets.loadBuffer("GameOverSound","../rec/GameOverSound.wav");
        _game_over_sound.setBuffer(_data->assets.getBuffer("GameOverSound"));



    }

    void GamePlayState::handleInput()
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
                    if (block.is_inside_grid(-1, 0))
                    {

                        bool is_touching_other = false;
                        for (int i = 0; i < 4; i++)
                        {
                            int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE + 1)) - 1;
                            int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE + 1));
                            if (grid[x_index][y_index] != 7)
                            {
                                is_touching_other = true;
                                break;
                            }
                        }
                        if (!is_touching_other)
                        {
                            _move_left_right_sound.play();
                            block.move_left();
                        }
                    }
                }
                if (evt.key.code == sf::Keyboard::Right)
                {
                    if (block.is_inside_grid(1, 0))
                    {
                        bool is_touching_other = false;
                        for (int i = 0; i < 4; i++)
                        {
                            int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE + 1)) + 1;
                            int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE + 1));
                            if (grid[x_index][y_index] != 7)
                            {
                                is_touching_other = true;
                                break;
                            }
                        }
                        if (!is_touching_other)
                        {
                            _move_left_right_sound.play();

                            block.move_right();
                        }
                    }
                }
                if (evt.key.code == sf::Keyboard::Up)
                {
                    _move_up_sound.play();
                    rotate();
                }
                if (evt.key.code == sf::Keyboard::Down)
                {
                    if (block.is_inside_grid(0, 1))
                    {
                        bool is_touching_other = false;
                        for (int i = 0; i < 4; i++)
                        {
                            int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE + 1));
                            int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE + 1)) + 1;
                            if (grid[x_index][y_index] != 7)
                            {
                                is_touching_other = true;
                                break;
                            }
                        }
                        if (!is_touching_other)
                        {
                            _move_down_sound.play();
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
    void GamePlayState::update(float dt)
    {
        // filling id getting data into grid
        if (block.is_locked())
        {
            int id = block.get_shape_id();
            for (int i = 0; i < 4; i++)
            {
                int x_index, y_index;
                x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE + 1));
                y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE + 1));
                grid[x_index][y_index] = id;
            }

            // clearing row
            int row_cleared_count = 0;
            for (int row = 0; row < 20; row++)
            {
                bool is_a_row_filled = true;
                for (int column = 0; column < 10; column++)
                {
                    if (grid[column][row] == 7)
                    {
                        is_a_row_filled = false;
//                        std::cout << "The row is not filled" << std::endl;
                        std::cout << column << " " << is_a_row_filled << std::endl;
                        break;
                    }
                }
                // Updating Score
                if (is_a_row_filled == true)
                {
                    row_cleared_count++;
                    score_value += pow(10, row_cleared_count + 1);
                }
                // Clears and shifts the row
                if (is_a_row_filled == true)
                {
                            _clear_sound.play();
                            float interval = 0.5;
                            float accumulated_time_anim = 0;
                            float time_anim = 0;

                            // Stopping program for 0.1 seconds
                            while (1)
                            {
                                time_anim = _clock.getElapsedTime().asSeconds();
                                _clock.restart();
                                accumulated_time_anim += time_anim;
                                // Row clearing Animation
                                for (int i = 0; i < 10; i++)
                                {
                                    sf::RectangleShape rect(sf::Vector2f(30, 30));
                                    rect.setFillColor(sf::Color::White);
                                    rect.setPosition(((17+i) * (30 + 1)), ((row+1)* (30 + 1)));
                                    _data->window.draw(rect);
                                    _data->window.display();
                                    
                                }
                                if (accumulated_time_anim > interval)
                                {
                                    accumulated_time_anim = 0;
                                    break;
                                }
                            }
                    if (row > 0)
                    {
                        for (row; row > 0; row--)
                        {
                            for (int column = 0; column < 10; column++)
                            {
                                grid[column][row] = grid[column][row - 1];
//                                std::cout << "clearing row" << std::endl;
                            }
                        }
                    }
                    if (row == 0)
                    {
                        for (int column = 0; column < 10; column++)
                        {
                            grid[column][0] = 7;
//                            std::cout << "clearing 1st row" << std::endl;
                        }
                    }
                }
            }


            block(_data, next_shape_id);
            next_block(_data, next_shape_id = generate_shape_id());

            // Load Gameover state
            if(is_game_over){
                _game_over_sound.play();
                _data->machine.addState(StateRef(new GameOverState(_data, score_value)), true);
            }
        }

        // timer

        time = _clock.getElapsedTime().asSeconds();
        _clock.restart();
        accumulated_time += time;

        if (accumulated_time > delay)
        {
            // movedown
            if (block.is_inside_grid(0, 1))
            {
                bool is_touching_other = false;
                for (int i = 0; i < 4; i++)
                {
                    int x_index = static_cast<int>((block.cells[i].get_x() - X_BOARD) / (CELL_SIZE + 1));
                    int y_index = static_cast<int>((block.cells[i].get_y() - Y_BOARD) / (CELL_SIZE + 1)) + 1;
                    if (grid[x_index][y_index] != 7)
                    {
                        is_touching_other = true;
                        block.set_locked(true);
                        break;
                    }
                }
                if (!is_touching_other)
                {
                    _move_down_sound.play();
                    block.move_down();
                }
            }
            else
            {
                block.set_locked(true);
            }

            accumulated_time = 0;
        }

        // Game Over
        for (int i = 0; i < 10; i++)
        {
            if (grid[i][0] != 7)
            {
                is_game_over = true;
                break;
            }
        }



    }
    void GamePlayState::render(float dt)
    {

        _data->window.clear(sf::Color::Black);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cell.setTextureRect(sf::IntRect(CELL_SIZE * grid[i][j], 0, CELL_SIZE, CELL_SIZE));
                cell.setPosition(((i + 17) * (CELL_SIZE + 1)), ((j + 1) * (CELL_SIZE + 1)));
                _data->window.draw(cell);
            }
        }
        for (int k = 0; k < 4; k++)
        {
            block.cells[k].set_sprite();
            block.cells[k].draw();
        }
        
        //Draw Next Tetromino 
        next_block.set_reference_position();
        for (int k = 0; k < 4; k++)
        {
            next_block.cells[k].set_sprite();
            next_block.cells[k].draw();
        }

        // Score Display
        _score.setFont(_data->assets.getFont("Bebas"));
        _score.setString("Score: " + std::to_string(score_value));
        _score.setCharacterSize(30);
        _score.setFillColor(sf::Color::White);
        _score.setPosition(X_NEXT_BLOCK - CELL_SIZE, Y_NEXT_BLOCK + CELL_SIZE*6 );
        _data->window.draw(_score);


        _data->window.draw(_NextTetrominoFrame);
        _data->window.draw(_GridFrame);

        _data->window.display();


    }

    int GamePlayState::generate_shape_id()
    {
        std::random_device rd;        // Seed generator with a true random number from the system
        std::mt19937 generator(rd()); // Mersenne Twister engine

        // Define the range for random numbers
        std::uniform_int_distribution<int> distribution(0, 6); // Range: [1, 100]

        // Generate and print random numbers
        int random_number = distribution(generator);
        return random_number;
    }

    void GamePlayState::calc_rotated_pts()
    {
        for (int i = 0; i < 4; i++)
        {
            x_rotated_pts[i] = block.get_rotated_x(block.cells[i]);
            y_rotated_pts[i] = block.get_rotated_y(block.cells[i]);
        }
    }

    void GamePlayState::rotate()
    {
        if (block.get_shape_id() != 6)
        {
            calc_rotated_pts();
            bool rotation_touching_other = false;
            for (int i = 0; i < 4; i++)
            {
                int x_index = static_cast<int>((x_rotated_pts[i] - X_BOARD) / (CELL_SIZE + 1));
                int y_index = static_cast<int>((y_rotated_pts[i] - Y_BOARD) / (CELL_SIZE + 1));
                if (grid[x_index][y_index] != 7)
                {
                    rotation_touching_other = true;
                    break;
                }
            }
            if (!rotation_touching_other)
            {
                block.calc_extreme_x_pos();
                if ((block.x_smallest >= X_BOARD) && (block.x_largest <= X_BOARD + (CELL_SIZE + 1) * 9))
                {
                    for (int i = 0; i < 4; i++)
                    {
                        block.cells[i].set_position(x_rotated_pts[i], y_rotated_pts[i]);
                    }
                }
                else
                {
                    if (block.x_smallest < X_BOARD)
                    {
                        float diff = X_BOARD - block.x_smallest;
                        for (int i = 0; i < 4; i++)
                        {
                            x_rotated_pts[i] += diff;
                        }
                        bool shift_touching_other = false;
                        for (int i = 0; i < 4; i++)
                        {
                            int x_index = static_cast<int>((x_rotated_pts[i] - X_BOARD) / (CELL_SIZE + 1));
                            int y_index = static_cast<int>((y_rotated_pts[i] - Y_BOARD) / (CELL_SIZE + 1));
                            if (grid[x_index][y_index] != 7)
                            {
                                shift_touching_other = true;
                                break;
                            }
                        }
                        if (!shift_touching_other)
                        {
                            for (int i = 0; i < 4; i++)
                            {
                                block.cells[i].set_position(x_rotated_pts[i], y_rotated_pts[i]);
                            }
                        }
                    }
                    if (block.x_largest > X_BOARD + (CELL_SIZE + 1) * 9)
                    {
                        float diff = block.x_largest - (X_BOARD + (CELL_SIZE + 1) * 9);
                        for (int i = 0; i < 4; i++)
                        {
                            x_rotated_pts[i] -= diff;
                        }
                        bool shift_touching_other = false;
                        for (int i = 0; i < 4; i++)
                        {
                            int x_index = static_cast<int>((x_rotated_pts[i] - X_BOARD) / (CELL_SIZE + 1));
                            int y_index = static_cast<int>((y_rotated_pts[i] - Y_BOARD) / (CELL_SIZE + 1));
                            if (grid[x_index][y_index] != 7)
                            {
                                shift_touching_other = true;
                                break;
                            }
                        }
                        if (!shift_touching_other)
                        {
                            for (int i = 0; i < 4; i++)
                            {
                                block.cells[i].set_position(x_rotated_pts[i], y_rotated_pts[i]);
                            }
                        }
                    }
                }
            }
        }
    }
}