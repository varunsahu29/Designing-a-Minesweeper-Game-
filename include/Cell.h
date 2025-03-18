#pragma once
#include <iostream>

class Cell {
private:
    bool isMine;
    bool isRevealed;
    bool isFlagged;
    int adjacentMines;

public:
    Cell();
    
    void setMine();
    bool hasMine() const;

    void reveal();
    bool isCellRevealed() const;

    void toggleFlag();
    bool isCellFlagged() const;

    void setAdjacentMines(int count);
    int getAdjacentMines() const;
};