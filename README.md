### **Sudoku solver in C++**
This repository contains a simple Sudoku solver implemented in C++. The solver uses a recursive backtracking algorithm to find the solution to a given Sudoku puzzle.

### **Features**
**Input Method:** The program takes a 9x9 Sudoku grid as input. The grid should be entered row by row, with each row represented as a single integer where empty cells are denoted by zeros.
 **Recursive Backtracking Algorithm:** The solver uses a recursive backtracking technique to explore all possible placements of numbers and find the correct solution. Before a number is placed into an empty cell, a check is run to ensure the number will fit into the row, column and 3x3 sub-grid without repetition.

###  **Getting Started**

**Prerequisites**
To run this program, you need:

 A C++ compiler (e.g., GCC, Clang, MSVC)

**Save the code:** Copy and paste the raw code into any text editor and save it with a  '.cpp' extension.
**Compile and run:** Run this command on your terminal to compile the program 
```
g++ --"path\to\sudoku_solver.cpp" -o sudoku_solver.exe
```
Once the compilation is complete run the program: 
```
sudoku_solver.exe
```
### **How to use**
When you run the program, you will be prompted to enter the digits of the first row of the sudoku puzzle without including commas, spaces, or any other characters. Use "0" to represent an empty cell. After entering the digits, press "Enter". Repeat this process for the second row and so on, until all nine rows are filled in. Once all the rows are entered, the unsolved sudoku will be displayed on the console, followed immediately by the solved sudoku. If the given sudoku has no solution, you will receive an error message. Keep in mind that if the sudoku is a valid one (e.g., from a newspaper or an app), a solution should exist, and an error may have occurred during input.

