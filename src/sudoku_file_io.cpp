/**
 * @file sudoku_file_io.cpp
 * @brief Implementation file for the SudokuFileIO class
 * @date December 21, 2023
 * @author Damjan Vincic
*/

#include "../include/sudoku_file_io.h"
#include <fstream>

std::vector<std::vector<unsigned short>> SudokuFileIO::read(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        int i = 0;
        std::vector<std::vector<unsigned short>> board(9, std::vector<unsigned short>(9, 0));
        while (getline(file, line)) {
            for (int j = 0; j < line.length(); ++j) {
                board[i][j] = line[j] == ' ' ? 0 : line[j] - '0';
            }
            ++i;
        }
        file.close();
        return board;
    }
    else {
        throw std::runtime_error("Unable to open file");
    }
}

void SudokuFileIO::write(const std::string& filename, const Sudoku9& sudoku) {
    std::ofstream file(filename);

    if (file.is_open()) {
        Board board = sudoku.getBoard();
        for (int i = 0; i < 9; ++i) {
            std::string line;
            for (int j = 0; j < 9; ++j) {
                line += board[i][j] == 0 ? ' ' : board[i][j] + '0';
            }
            file << line << std::endl;
        }
        file.close();
    }
    else {
        throw std::runtime_error("Unable to open file");
    }
}