This is an experimental Sudoku solver and generator that I
wrote to help me learn Python, essentially being the first
python program that I wrote. The code is a little messy as
I wanted to try many different things!


It does not generate boards with unique solutions, as I
did not wish to spend more time perfecting the algorithm.
However, it does generate a board, is able to solve boards
within reasonable time, and checks whether the solution
provided is valid.


Dependencies:
* Pygame


Board generation:
1. It solves an empty sudoku grid using a solver that uses
randomness.
2. It then erases a random number of squares.

Optionally, a C++ solver is included, and can be used from
inside the python program. Compilation is left up to the
user!