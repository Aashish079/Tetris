#pragma once

constexpr int CELL_SIZE = 30;

constexpr int ROWS = 10;
constexpr int COLUMNS = 20;

constexpr int X_BOARD = 17 * (CELL_SIZE+1);
constexpr int Y_BOARD = (CELL_SIZE + 1);

constexpr int X_SPAWN = X_BOARD + 4 * (CELL_SIZE+1);
constexpr int Y_SPAWN = Y_BOARD;

constexpr int shapes[7][4] =
        {
                {1, 3, 5, 7}, //I
                {2, 4, 5, 7}, //Z
                {3, 5, 4, 6}, //S
                {3, 5, 4, 7}, //T
                {2, 3, 5, 7}, //L
                {3, 5, 7, 6}, //J
                {2, 3, 4, 5}  //O
        };




