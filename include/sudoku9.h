/**
 * @file sudoku9.h
 * @brief Declaration of the Sudoku9 class
 * @date December 21, 2023
 * @author Damjan Vincic
 */

#ifndef SUDOKU_SUDOKU9_H
#define SUDOKU_SUDOKU9_H
#include <vector>
#include "board.h"

/**
 * @class Sudoku9
 * @brief Class for sudoku representation and related methods
 */
class Sudoku9 {
    /**
     * @brief Board object representing the original sudoku board
    */
    Board originalBoard;

    /**
     * @brief Board object representing the sudoku board
    */
    Board board;

    /**
     * @brief Number of valid cells in the sudoku board
    */
    int numberOfValidCells = 0;

    /**
     * @brief Number of invalid cells in the sudoku board
    */
    int numberOfInvalidCells = 0;

    /**
     * @brief Number of games played
    */
    static int numberOfGames;
public:
    /**
     * @brief Empty constructor for the Sudoku9 class
     */
    Sudoku9();

    /**
     * @brief Constructor for the Sudoku9 class
     * @param board 2D vector representing the sudoku board
     */
    Sudoku9(const std::vector<std::vector<unsigned short>>& board);

    /**
     * @brief Copy constructor for the Sudoku9 class
     * @param other Sudoku9 object to be copied
     */
    Sudoku9& operator=(const Sudoku9& other);

    /**
     * @brief Returns the original sudoku board
     * @return The original sudoku board
     */
    Board getOriginalBoard() const;

    /**
     * @brief Returns the solved sudoku board
     * @return Solved sudoku board
     */
    Board getBoard() const;

    /**
     * @brief Solves the sudoku board
     * @return True if the sudoku is solved, false otherwise
     */
    bool solveSudoku();

    /**
     * @brief Generates a sudoku board
     */
    void generateSudoku();

    /**
     * @brief Checks if the sudoku board is solved, and updates the corresponding attributes.
    */
    void checkSolution();

    /**
     * @brief Returns the number of valid cells
     * @return Number of valid cells
    */
    int getNumberOfValidCells() const;

    /**
     * @brief Returns the number of invalid cells
     * @return Number of invalid cells
    */
    int getNumberOfInvalidCells() const;

    /**
     * @brief Returns the number of games played
     * @return Number of games played
    */
    static int& numberOfGamesPlayed();

    /**
     * @brief Sets the solution of the sudoku board
     * @param solution The solution of the sudoku board
     */
    void setSolution(const std::vector<std::vector<unsigned short>>& solution);
};
#endif //SUDOKU_SUDOKU9_H
