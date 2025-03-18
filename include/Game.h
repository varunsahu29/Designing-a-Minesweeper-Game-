#pragma once
#include "Board.h"
#include "Logger.h"
#include <iostream>
#include <memory>
#include <mutex>

class Game {
private:
    bool gameOver;
    std::mutex gameMutex;
    friend class GameTest; // For testing purposes
    std::unique_ptr<Board> board; // For dynamic nature use pointer
    
public:
    Game(int rows, int cols, int mines);
    
    void startGame();
    void handleUserInput();
    void checkWinCondition();
    bool isGameOver() const { return gameOver; }
};
