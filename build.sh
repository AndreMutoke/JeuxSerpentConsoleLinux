#! /usr/bin/bash
echo "Compilation du programme"
g++ main.cpp pos/coord.cpp Game_Snake/food.cpp Game_Snake/snake_game.cpp color/color.cpp board/board.cpp -o snakeGame -Wextra -Wall