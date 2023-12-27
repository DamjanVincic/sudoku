/**
 * @file board.cpp
 * @brief Implementation file for the Board class
 * @date December 27, 2023
 * @author Damjan Vincic
*/

#include "../include/board.h"
#include <cstdlib>
#include <iostream>

Board::Board() : board(std::vector<std::vector<unsigned short>>(9, std::vector<unsigned short>(9, 0))) { }

Board::Board(const std::vector<std::vector<unsigned short>>& board) : board(board) { }

Board::Board(const Board& other) : board(other.getBoard()) { }

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        board = other.getBoard();
    }
    return *this;
}

bool Board::isSubgridSafe(int row, int col, unsigned short num) {
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

bool Board::isSafe(int row, int col, unsigned short num) {
    // Check if the number is already in the row or column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // Since we already checked rows and columns, if the subgrid is safe, the number can be placed
    return isSubgridSafe(row, col, num);
}

void Board::fillDiagonalSubgrids() {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; ++j) {
            int num = rand() % 9 + 1;
            while (!isSubgridSafe(i + j/3, i + j%3, num)) {
                num = rand() % 9 + 1;
            }
            board[i + j/3][i + j%3] = num;
        }
    }
}

void Board::print() {
    for (std::vector<unsigned short>& row : board) {
        for (unsigned short& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<unsigned short>> Board::getBoard() const {
    return board;
}

std::vector<unsigned short>& Board::operator[](int i) {
    return board[i];
}

const std::vector<unsigned short>& Board::operator[](int i) const {
    return board[i];
}