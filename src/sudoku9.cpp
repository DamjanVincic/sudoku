/**
 * @file sudoku9.cpp
 * @brief Implementation file for the Sudoku9 class
 * @date December 21, 2023
 * @author Damjan Vincic
 */

#include "../include/sudoku9.h"
#include <iostream>

Sudoku9::Sudoku9() : originalBoard(), board() { }

Sudoku9::Sudoku9(const std::vector<std::vector<unsigned short>>& board) : originalBoard(board), board(board) { }

Sudoku9& Sudoku9::operator=(const Sudoku9& other) {
    if (this != &other) {
        // for (int i = 0; i < 9; ++i) {
        //     for (int j = 0; j < 9; ++j)
        //         board[i][j] = other[i][j];
        // }
        board = other.getBoard();
        originalBoard = other.getOriginalBoard();
        numberOfValidCells = numberOfInvalidCells = 0;
    }
    return *this;
}

Board Sudoku9::getOriginalBoard() const {
    return originalBoard;
}

Board Sudoku9::getBoard() const {
    return board;
}

bool Sudoku9::solveSudoku() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (board.isSafe(i, j, num)) {
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

void Sudoku9::generateSudoku() {
    srand(time(nullptr));
    board.fillDiagonalSubgrids();
    solveSudoku();
    int max = 81 - 17; // At least 17 squares must be available
    int min = 81/2; // At least half of the squares to be removed for optimal difficulty
//    int min = 9*3; // At least 3 numbers removed from each subgrid (on average)
    int numToRemove = rand() % (max - min + 1) + min;
    for (int i = 0; i < numToRemove; ++i) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (board[row][col] != 0) {
            board[row][col] = 0;
        } else {
            --i;
        }
    }
    originalBoard = board;
}

// void Sudoku9::checkSolution() {
//     std::unordered_set<unsigned short> rowSet, colSet, boxSet;

//     for (int i = 0; i < 9; ++i) {
//         rowSet.clear();
//         colSet.clear();
//         boxSet.clear();
//         for (int j = 0; j < 9; ++j) {
//             if (board[i][j] != 0) {
//                 if (rowSet.find(board[i][j]) != rowSet.end())
//                     numberOfInvalidCells++;
//                 rowSet.insert(board[i][j]);
//             }
//             if (board[j][i] != 0) {
//                 if (colSet.find(board[j][i]) != colSet.end())
//                     numberOfInvalidCells++;
//                 colSet.insert(board[j][i]);
//             }
//             int boxRow = i - i % 3 + j / 3;
//             int boxCol = i * 3 % 9 + j % 3;
//             if (board[boxRow][boxCol] != 0) {
//                 if (boxSet.find(board[boxRow][boxCol]) != boxSet.end())
//                     numberOfInvalidCells++;
//                 boxSet.insert(board[boxRow][boxCol]);
//             }
//         }
//     }
// }

void Sudoku9::checkSolution() {
    unsigned short num;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (originalBoard[i][j] == 0) {
                num = board[i][j];
                board[i][j] = 0;
                if (board.isSafe(i, j, num))
                    ++numberOfValidCells;
                else
                    ++numberOfInvalidCells;
                board[i][j] = num;
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

int Sudoku9::numberOfGames = 0;

int& Sudoku9::numberOfGamesPlayed() {
    return numberOfGames;
}

void Sudoku9::setSolution(const std::vector<std::vector<unsigned short>> &solution) {
    board = solution;
    numberOfInvalidCells = numberOfValidCells = 0;
}