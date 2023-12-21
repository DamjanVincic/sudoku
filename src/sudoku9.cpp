/**
 * @file sudoku9.cpp
 * @brief Implementation file for the Sudoku9 class
 * @date December 21, 2023
 * @author Damjan Vincic
 */

#include "../include/sudoku9.h"
#include <iostream>
#include <unordered_set>

Sudoku9::Sudoku9() : board(std::vector<std::vector<unsigned short>>(9, std::vector<unsigned short>(9, 0))) { }

Sudoku9::Sudoku9(const std::vector<std::vector<unsigned short>>& board) : board(std::vector<std::vector<unsigned short>>(9, std::vector<unsigned short>(9, 0))) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            this->board[i][j] = board[i][j];
    }
}

Sudoku9& Sudoku9::operator=(const Sudoku9& other) {
    if (this != &other) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j)
                board[i][j] = other[i][j];
        }
    }
    return *this;
}

std::vector<unsigned short> Sudoku9::operator[](int i) {
    return board[i];
}

const std::vector<unsigned short> Sudoku9::operator[](int i) const {
    return board[i];
}

bool Sudoku9::isSafe(int row, int col, unsigned short num) {
    // Check if the number is already in the row or column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // Check if the number is already in the 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; ++i) {
        for (int j = boxCol; j < boxCol + 3; ++j) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool Sudoku9::solveSudoku() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(i, j, num)) {
                        board[i][j] = num;
                        if (solveSudoku())
                            return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Sudoku9::fillDiagonalSubgrids() {
    for (int i = 0; i < 9; i += 3) {
        for (int num = 1; num <= 9; ++num) {
            int row = rand() % 3 + i;
            int col = rand() % 3 + i;

            while (!isSafe(row, col, num)) {
                row = rand() % 3 + i;
                col = rand() % 3 + i;
            }
            board[row][col] = num;
        }
    }
}

void Sudoku9::generateSudoku() {
    srand(time(nullptr));
    fillDiagonalSubgrids();
    solveSudoku();
    int numToRemove = rand() % 50 + 20;
    for (int i = 0; i < numToRemove; ++i) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (board[row][col] != 0) {
            board[row][col] = 0;
        } else {
            --i;
        }
    }
}

void Sudoku9::printBoard() {
    for (std::vector<unsigned short>& row : board) {
        for (unsigned short& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void Sudoku9::checkSolution() {
    std::unordered_set<unsigned short> rowSet, colSet, boxSet;

    for (int i = 0; i < 9; ++i) {
        rowSet.clear();
        colSet.clear();
        boxSet.clear();
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != 0) {
                if (rowSet.find(board[i][j]) != rowSet.end())
                    numberOfInvalidCells++;
                rowSet.insert(board[i][j]);
            }
            if (board[j][i] != 0) {
                if (colSet.find(board[j][i]) != colSet.end())
                    numberOfInvalidCells++;
                colSet.insert(board[j][i]);
            }
            int boxRow = i - i % 3 + j / 3;
            int boxCol = i * 3 % 9 + j % 3;
            if (board[boxRow][boxCol] != 0) {
                if (boxSet.find(board[boxRow][boxCol]) != boxSet.end())
                    numberOfInvalidCells++;
                boxSet.insert(board[boxRow][boxCol]);
            }
        }
    }
}

int Sudoku9::getNumberOfValidCells() const {
    return numberOfValidCells;
}

int Sudoku9::getNumberOfInvalidCells() const {
    return numberOfInvalidCells;
}

int& Sudoku9::numberOfGamesPlayed() {
    return numberOfGames;
}

int Sudoku9::numberOfGames = 0;