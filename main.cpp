#include "Game.h"
#include <iostream>

int main() {
    int rows = 3, cols = 3, mines = 1;
    std::cout << "Starting Minesweeper with " << rows << "x" << cols << " board and " << mines << " mines.\n";

    Game game(rows, cols, mines);
    game.startGame();

    std::cout << "Game Over. Thanks for playing!\n";
    return 0;
}
