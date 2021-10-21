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

### Sequence of the application

Firstly, the user chooses the difficulty (default value = easy) and clicks the generate button. The program checks wich radio button is currently active. After that, the convenient number of cells will be filled with convenient numbers.

##### Structogram of the inputvalidation of the user

![structogram of cellValidation](https://github.com/JoBo33/Sudoku/blob/main/structogram%20cellTextChanged.png "structogram of cellvalidation")
