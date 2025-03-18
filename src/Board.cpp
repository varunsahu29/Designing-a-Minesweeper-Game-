#include "Board.h"

Board::Board(int r, int c, int m) : rows(r), cols(c), mines(m), grid(r, std::vector<Cell>(c))
{
    placeMines();
    calculateAdjacentMines();
}

void Board::revealCell(int x, int y)
{
    grid[x][y].reveal();
}

bool Board::isMineAt(int x, int y) const
{
    return grid[x][y].hasMine();
}

void Board::placeMines()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distRow(0, rows - 1);
    std::uniform_int_distribution<int> distCol(0, cols - 1);

    int placedMines = 0;
    while (placedMines < mines)
    {
        int x = distRow(gen);
        int y = distCol(gen);
        if (!grid[x][y].hasMine())
        {
            grid[x][y].setMine();
            placedMines++;
        }
    }
}

void Board::calculateAdjacentMines()
{
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            if (!grid[x][y].hasMine())
            {
                int count = 0;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny].hasMine())
                            count++;
                    }
                }
                grid[x][y].setAdjacentMines(count);
            }
        }
    }
}

void Board::displayBoard(bool revealAll) const
{
    for (const auto &row : grid)
    {
        for (const auto &cell : row)
        {
            if (revealAll || cell.isCellRevealed())
            {
                std::cout << (cell.hasMine() ? "*" : std::to_string(cell.getAdjacentMines())) << " ";
            }
            else
            {
                std::cout << "#";
            }
        }
        std::cout << "\n";
    }
}
int Board::countRevealedCells() const
{
    int count = 0;
    for (const auto &row : grid)
    {
        for (const auto &cell : row)
        {
            if (cell.isCellRevealed())
                count++;
        }
    }
    return count;
};
int Board::getTotalCells() const { return rows * cols; }
int Board::getMineCount() const { return mines; }
