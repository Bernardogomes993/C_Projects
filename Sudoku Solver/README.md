# Sudoku Solver in C
This project is about a sudoku solver this project uses a recursive algorithm to solve the sudoku puzzle.

## Functionalities
* **Dinamic Input**: The user inputs line by line each number of the puzzle, for the empty boxes
  the user must put the value `0`.
* **Input Validation**: The input validation makes sure that the numbers between `0` and `9` are
  correct.
* **Algorithm**: The algorithm sorts throught an array `[9][9]` and tests different values `0 - 9`
  and if the program reaches to an endpoint he cleans the previous box and puts the value `0`.

 ## How it works
 1. **isValid()** : This function loops through each line and each column and also in each box
    and verifies if the number are complient to the rules of the game.
2. **solveSudoku()**: This funtion goes to the puzzle until it finds zeros, if the function finds a zero
   the numbers between `0 - 9` are tested.
   If the number is valid the function goes to the next zero and do the same tests.
   If the next box fails the function goes to the previous box and puts  a `zero` and tests the next values.
   
