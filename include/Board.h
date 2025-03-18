#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <memory>
#include "Cell.h"

class Board {
private:
    int rows, cols, mines;
    std::vector<std::vector<Cell>> grid;

    void placeMines();
    void calculateAdjacentMines();
    friend class GameTest;

public:
    Board(int rows, int cols, int mines);
    
    void revealCell(int x, int y);
    bool isMineAt(int x, int y) const;
    void displayBoard(bool revealAll = false) const;
    int countRevealedCells() const;
    int getTotalCells() const ;
    int getMineCount() const ;
};
