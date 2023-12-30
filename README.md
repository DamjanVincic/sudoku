# Sudoku in C++

Project for the 3rd semester, course Software Engineering and Informational Technologies at Faculty of Technical Sciences, University of Novi Sad, 2023.

## Build

Requirements:
- CMake

Commands to build the project:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
`build` is the directory where the build files will be stored. You can rename it.

## Run

To run the project:
```bash
./sudoku <path_to_input_file> <path_to_output_file>
```

`path_to_input_file` is the path to the file containing the sudoku puzzle.
<br/>
An example of a valid file:
```
4 1 . | . . . | . . 7
2 . . | . . 6 | . . . 
6 . . | . . . | . . .
------+-------+------
. . 2 | 5 . 9 | . . 4 
. 4 . | . . . | 2 . .
. . . | . 1 . | . 3 . 
------+-------+------
. . . | . . . | . . . 
. 8 . | . . . | 9 . .
3 . 5 | 9 . 1 | . . . 
```

`path_to_output_file` is the path to the file where the solution will be stored. If the file doesn't exist, it will be created. If it exists, it will be overwritten.

## Game Loop

1. Load a sudoku board from input file, or generate a new one.
1. Let the program solve the sudoku board, or enter your solution to output file and check if it's correct.
1. Play again or exit the program.