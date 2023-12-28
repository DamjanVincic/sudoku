/**
 * @file sudoku_file_io.cpp
 * @brief Implementation file for the SudokuFileIO class
 * @date December 28, 2023
 * @author Damjan Vincic
*/

#include "../include/sudoku_file_io.h"
#include <fstream>

std::vector<std::vector<unsigned short>> SudokuFileIO::read(const std::string& filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        std::vector<std::vector<unsigned short>> board;
        std::vector<unsigned short> row;
        while (std::getline(file, line)) {
            for (char& c : line) {
                if (isdigit(c)) {
                    row.push_back(c - '0');
                } else if (c == '.') {
                    row.push_back(0);
                }
            }
            if (!row.empty()) {
                board.push_back(row);
                row.clear();
            }
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
        file << sudoku.getBoard();
    }
    else {
        throw std::runtime_error("Unable to open file");
    }
}