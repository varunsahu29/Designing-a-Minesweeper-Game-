#include "Game.h"
#include "Board.h"

Game::Game(int rows, int cols, int mines) : board(std::make_unique<Board>(rows, cols, mines)), gameOver(false) {
    Logger::getInstance()->log("Game initialized with board size " + std::to_string(rows) + "x" + std::to_string(cols), LogLevel::INFO);
}

void Game::startGame() {
    Logger::getInstance()->log("Game started", LogLevel::INFO);
    while (!gameOver) {
        board->displayBoard();
        handleUserInput();
        checkWinCondition();
    }
}

void Game::handleUserInput() {
    int x, y;
    std::cout << "Enter row and column to reveal: ";
    std::cin >> x >> y;
    
    std::lock_guard<std::mutex> lock(gameMutex);
    if (board->isMineAt(x, y)) {
        Logger::getInstance()->log("Player hit a mine at (" + std::to_string(x) + ", " + std::to_string(y) + ")", LogLevel::ERROR);
        std::cout << "Game Over! You hit a mine.\n";
        gameOver = true;
    } else {
        Logger::getInstance()->log("Revealed cell at (" + std::to_string(x) + ", " + std::to_string(y) + ")", LogLevel::INFO);
        board->revealCell(x, y);
    }
}

void Game::checkWinCondition() {
    int revealedCells = board->countRevealedCells();
    int totalCells = board->getTotalCells();
    int mineCount = board->getMineCount();

    if (revealedCells == totalCells - mineCount) {
        Logger::getInstance()->log("Player has won the game!", LogLevel::INFO);
        std::cout << "Congratulations! You've won the game.\n";
        gameOver = true;
    }
}