/**
 * @file sudoku_file_io.h
 * @brief Declaration of the SudokuFileIO class
 * @date December 21, 2023
 * @author Damjan Vincic
 */

#ifndef SUDOKU_SUDOKU_FILE_IO_H
#define SUDOKU_SUDOKU_FILE_IO_H
#include <string>
#include "sudoku9.h"

/**
 * @class SudokuFileIO
 * @brief Class for reading and writing Sudoku9 objects to and from files
 */
class SudokuFileIO {
public:
    /**
     * @brief Reads a sudoku board from a file.
     * @return Sudoku9 object
    */
    Sudoku9 read(const std::string& filename);

    /**
     * @brief Writes a sudoku board to a file.
    */
    void write(const std::string& filename, const Sudoku9& sudoku);
};
#endif //SUDOKU_SUDOKU_FILE_IO_H
