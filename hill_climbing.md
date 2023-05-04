# Hill Climbing Algorithm for Solving N-Queens Problem

The N-Queens problem is a classic problem in computer science and mathematics that involves placing N chess queens on an NxN chessboard such that no two queens threaten each other. The problem is known to be NP-complete, which means that finding an optimal solution is computationally expensive for larger values of N.

The Hill Climbing algorithm is a heuristic search algorithm that attempts to find the optimal solution by making incremental improvements. The algorithm starts with an initial solution and then repeatedly evaluates the neighboring solutions and selects the one with the highest value (i.e., the one that has the fewest conflicts). This process continues until a local maximum is reached.

In this program, we implement the Hill Climbing algorithm to solve the N-Queens problem. The program randomly generates an initial state for the chessboard, applies the Hill Climbing algorithm to find the optimal solution, and repeats the process for a set number of attempts. The program also calculates and displays the statistical analysis of the execution time of the algorithm.

## Implementation

The program is implemented in C++ and consists of the following classes and functions:

- `NQueensProblem`: A class that represents the N-Queens problem. It contains the size of the chessboard and the initial state of the board (randomly generated).
- `value()`: A method of the `NQueensProblem` class that calculates the number of conflicts (i.e., the number of pairs of queens that threaten each other) in a given state of the chessboard.
- `successors()`: A method of the `NQueensProblem` class that generates all possible successor states of a given state by moving one queen to a different row in its column.
- `get_highest_valued_successor()`: A method of the `NQueensProblem` class that returns the successor state with the highest value.
- `hill_climbing()`: A function that implements the Hill Climbing algorithm to find the optimal solution for the N-Queens problem.
- `solve_n_queens()`: A function that generates an instance of the N-Queens problem, applies the Hill Climbing algorithm to find the optimal solution, and returns a boolean indicating whether the solution was found.
- `print_state()`: A function that prints the chessboard state in a readable format.
- `main()`: The main function that runs the program. It generates a set number of instances of the N-Queens problem, applies the Hill Climbing algorithm to each instance, and calculates and displays the statistical analysis of the execution time.

## Results

The algorithm was run 100 times, with number of queens being 8.


```
Solution found on attempt 1:
. . . . . . Q . 
. . . . Q . . . 
. . Q . . . . . 
Q . . . . . . . 
. . . . . Q . . 
. . . . . . . Q 
. Q . . . . . . 
. . . Q . . . . 

Solution found on attempt 2:
. . . . Q . . . 
. Q . . . . . . 
. . . . . Q . . 
Q . . . . . . . 
. . . . . . Q . 
. . . Q . . . . 
. . . . . . . Q 
. . Q . . . . . 

Solution found on attempt 11:
. . . Q . . . . 
. . . . . Q . . 
Q . . . . . . . 
. . . . Q . . . 
. Q . . . . . . 
. . . . . . . Q 
. . Q . . . . . 
. . . . . . Q . 

Solution found on attempt 12:
. . . . . . Q . 
. . Q . . . . . 
Q . . . . . . . 
. . . . . Q . . 
. . . . . . . Q 
. . . . Q . . . 
. Q . . . . . . 
. . . Q . . . . 

Solution found on attempt 14:
. . Q . . . . . 
. . . . . . Q . 
. Q . . . . . . 
. . . . . . . Q 
. . . . . Q . . 
. . . Q . . . . 
Q . . . . . . . 
. . . . Q . . . 

Solution found on attempt 19:
. . Q . . . . . 
. . . . . Q . . 
. Q . . . . . . 
. . . . . . Q . 
. . . . Q . . . 
Q . . . . . . . 
. . . . . . . Q 
. . . Q . . . . 

Solution found on attempt 21:
. . . Q . . . . 
Q . . . . . . . 
. . . . Q . . . 
. . . . . . . Q 
. . . . . Q . . 
. . Q . . . . . 
. . . . . . Q . 
. Q . . . . . . 

Solution found on attempt 22:
. . Q . . . . . 
. . . . Q . . . 
. . . . . . Q . 
Q . . . . . . . 
. . . Q . . . . 
. Q . . . . . . 
. . . . . . . Q 
. . . . . Q . . 

Solution found on attempt 24:
. . . Q . . . . 
. . . . . . . Q 
Q . . . . . . . 
. . Q . . . . . 
. . . . . Q . . 
. Q . . . . . . 
. . . . . . Q . 
. . . . Q . . . 

Solution found on attempt 25:
. . Q . . . . . 
. . . . . Q . . 
. Q . . . . . . 
. . . . . . Q . 
Q . . . . . . . 
. . . Q . . . . 
. . . . . . . Q 
. . . . Q . . . 

Solution found on attempt 33:
. . . . . . . Q 
. Q . . . . . . 
. . . . Q . . . 
. . Q . . . . . 
Q . . . . . . . 
. . . . . . Q . 
. . . Q . . . . 
. . . . . Q . . 

Solution found on attempt 41:
Q . . . . . . . 
. . . . . Q . . 
. . . . . . . Q 
. . Q . . . . . 
. . . . . . Q . 
. . . Q . . . . 
. Q . . . . . . 
. . . . Q . . . 

Solution found on attempt 49:
. . . . Q . . . 
. Q . . . . . . 
. . . Q . . . . 
. . . . . . Q . 
. . Q . . . . . 
. . . . . . . Q 
. . . . . Q . . 
Q . . . . . . . 

Solution found on attempt 52:
. . . . Q . . . 
. . . . . . . Q 
. . . Q . . . . 
Q . . . . . . . 
. . Q . . . . . 
. . . . . Q . . 
. Q . . . . . . 
. . . . . . Q . 

Solution found on attempt 61:
. . . . . Q . . 
. . Q . . . . . 
. . . . . . Q . 
. Q . . . . . . 
. . . . . . . Q 
. . . . Q . . . 
Q . . . . . . . 
. . . Q . . . . 

Solution found on attempt 80:
. . . . Q . . . 
. . . . . . Q . 
. Q . . . . . . 
. . . . . Q . . 
. . Q . . . . . 
Q . . . . . . . 
. . . Q . . . . 
. . . . . . . Q 

Solution found on attempt 92:
. . . . . Q . . 
. . Q . . . . . 
Q . . . . . . . 
. . . . . . . Q 
. . . Q . . . . 
. Q . . . . . . 
. . . . . . Q . 
. . . . Q . . . 

Solved 17 out of 100
Success rate: 17.00%

Execution time statistics:
--------------------------
Minimum time taken: 103.00 µs
Maximum time taken: 167.00 µs
Average time taken: 22.02 µs
Standard deviation of time taken: 6.05 ms
```

## Statistical Analysis

The program runs the Hill Climbing algorithm for a set number of attempts (in this case, 100) and calculates the following statistics for the execution time:

- Minimum time taken: 103.00 µs
- Maximum time taken: 167.00 µs
- Average time taken: 22.02 µs
- Standard deviation: 6.05 ms
- Success rate: 17.00%

The statistical analysis shows that the Hill Climbing algorithm is fast, but it does not come to a solution during ~ 80% of its runs.

## Conclusion

The Hill Climbing algorithm is a simple and effective heuristic search algorithm for solving the N-Queens problem. The program demonstrates the implementation of the algorithm and provides a statistical analysis of the execution time. The program can be easily modified to solve other optimization problems that can be represented as a search problem.