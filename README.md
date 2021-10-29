# Sudoku

Sudoku is a logic puzzle. The ground of the typical Sudoku is a 9x9 grid. At the beginning, there are a few cells already filled with numbers from 1 to 9. The aim of the puzzle is that each cell is filled with one number while not breaking the following rules:
1. each row is filled by the numbers 1 to 9 
2. each column is filled by the numbers 1 to 9
3. each smaller grid (3x3) is filled by the numbers 1 to 9

The difficulty can be managed by the number of filled cells at the beginning.

### Sudoku GUI-Concept

The GUI contains the following widgets:
- TableView to display the Sudoku-grid
- 3x RadioButton to choose the difficulty (easy, normal, hard)
- PushButton to generate a Sudoku-grid

![Sudoku-GUI](https://github.com/JoBo33/Sudoku/blob/main/Sudoku-GUI-Concept.png "Sudoku GUI-Concept")

### How does the creation work?

Firstly, the user chooses the difficulty (default value = easy) and clicks the generate button. Due to this, the signal "clicked" of the button "generate" gets triggert and activates the slot "generateSudoku". In the following, the method to generate a Sudoku will be explained with help of structograms.

![generateSudoku structogram](https://github.com/JoBo33/Sudoku/blob/main/Diagrams/generateSudoku%20structogram.png "generateSudoku structogram")

The method is devided in three parts. The first part is that the diagonal grids are getting filled.  

![fillDiagonalGrids](https://github.com/JoBo33/Sudoku/blob/main/Diagrams/fillDiagonalGrids%20structogram.png "fillDiagonalGrids structogram")
![fillDiagonalGrids example](https://github.com/JoBo33/Sudoku/blob/main/Example/fillDiagonalGrids.png "fillDiagonalGrids example")
As one can see in the example, the diagonal grids are filled after the first part. The second part fills the rest of the grid with help of a recursive method.  

![fillReamining](https://github.com/JoBo33/Sudoku/blob/main/Diagrams/fillRemaining%20structogram.png "fillRemaining structogram")
![fillRemaining example](https://github.com/JoBo33/Sudoku/blob/main/Example/fillRemaining.png "fillRemaining example")
Here one can see that the Sudoku is actually solved. So, the final Sudoku is solvable in the end. In the third part, some entries of the solved Sudoku get deleted. The number of the deleted entries depends on the checked difficulty.

![removeEntries](https://github.com/JoBo33/Sudoku/blob/main/Diagrams/removeEntries%20structogram.png "removeEntries structogram")
![removeEntries example](https://github.com/JoBo33/Sudoku/blob/main/Example/removeEntries.png "RemoveEntries example")
  
The last structogram is about the validation of generated numbers. So the methods checks if the number is already part of the row, column or small grid.

![structogram of checkValue](https://github.com/JoBo33/Sudoku/blob/main/Diagrams/checkValue%20structogram.png "checkValue() structogram")


### To solve the Sudoku, the program uses a Backtracking-algorithm

#### What is actually Backtracking?
Backtracking is an algorithmic-technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point of time 

There are three types of problems in backtracking:   

1. Decision Problem – In this, we search for a feasible solution.
2. Optimization Problem – In this, we search for the best solution.
3. Enumeration Problem – In this, we find all feasible solutions.

#### solve the Sudoku
While solving the Sudoku, the method generates a value. If the number is a possible number, the number will be entered. If not, a new number will be generated. 

![solveSudoku](https://github.com/JoBo33/Sudoku/blob/main/Diagrams/solveSudoku%20structogram.png "solveSudoku structogram")
![solveSudoku example](https://github.com/JoBo33/Sudoku/blob/main/Example/solveSudoku.png "solveSudoku example")






