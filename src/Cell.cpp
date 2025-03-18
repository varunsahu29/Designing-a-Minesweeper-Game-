#include "Cell.h"

Cell::Cell() : isMine(false), isRevealed(false), isFlagged(false), adjacentMines(0) {}

void Cell::setMine() { isMine = true; }
bool Cell::hasMine() const { return isMine; }

void Cell::reveal() { isRevealed = true; }
bool Cell::isCellRevealed() const { return isRevealed; }

void Cell::toggleFlag() { isFlagged = !isFlagged; }
bool Cell::isCellFlagged() const { return isFlagged; }

void Cell::setAdjacentMines(int count) { adjacentMines = count; }
int Cell::getAdjacentMines() const { return adjacentMines; }
