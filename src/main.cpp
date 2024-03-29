/**
 * @file main.cpp
 * @brief Main file of the program
 * @date December 28, 2023
 * @author Damjan Vincic
*/

#include <iostream>
#include "../include/sudoku9.h"
#include "../include/sudoku_file_io.h"

int main(int argc, char* argv[]) {
    std::string challengeFilename = argv[1], solutionFilename = argv[2];
    Sudoku9 sudoku;

    char choice;
    while (true) {
        std::cout << "[1] Load a sudoku board.\n"
                     "[2] Generate a sudoku board.\n"
                     ">> ";
        
        std::cin >> choice;

        switch (choice) {
            case '1':
                try {
                    sudoku = SudokuFileIO::read(challengeFilename);
                } catch (std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                    continue;
                }
                break;
            case '2':
                sudoku.generateSudoku();
                SudokuFileIO::write(challengeFilename, sudoku);
                break;
            default:
                std::cout << "Invalid input." << std::endl;
                continue;
        }

        std::cout << "[1] Load solution\n"
                     "[2] Solve the sudoku\n"
                     ">> ";
        
        std::cin >> choice;

        switch(choice) {
            case '1':
                try {
                    sudoku.setSolution(SudokuFileIO::read(solutionFilename));
                } catch (std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                    continue;
                }
                break;
            case '2':
                if (!sudoku.solveSudoku()) {
                    std::cout << "The sudoku is not solvable." << std::endl;
                    continue;
                }
                SudokuFileIO::write(solutionFilename, sudoku);
                break;
            default:
                std::cout << "Invalid input." << std::endl;
                continue;
        }

        if (sudoku.checkSolution()) {
            std::cout << sudoku.getBoard();
            std::cout << "Number of valid cells: " << sudoku.getNumberOfValidCells() << std::endl;
            std::cout << "Number of invalid cells: " << sudoku.getNumberOfInvalidCells() << std::endl;
            std::cout << "Number of games played: " << ++Sudoku9::numberOfGamesPlayed() << std::endl;
        } else {
            std::cout << "The solution and the original board are not the same, or the solution is not complete." << std::endl;
        }

        std::cout << "[1] Continue\n"
                     "[2] Exit\n"
                     ">> ";

        std::cin >> choice;

        switch(choice) {
            case '1':
                break;
            case '2':
                return 0;
            default:
                std::cout << "Invalid input." << std::endl;
                return 0;
        }
    }

    return 0;
}
