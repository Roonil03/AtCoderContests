# C - 2 Directions vs 4 Directions
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 700 points

## Description:
There is an $N \times N$ grid, where $N$ is an integer at least 2. For $1 \le i, j \le N$, the cell at row $i$ from the top and column $j$ from the left is denoted by $(i, j)$.
Initially, all cells are black. For each cell $(i, j)$, a cost $A_{i, j}$ to change the color of the cell from black to white is given.
Alice and Bob play a game using this grid and one piece. The game consists of the following three steps.

**Step 1**
The referee specifies the cell where the piece is initially placed.

**Step 2**
Alice performs the following operation zero or more times:
* Choose a black cell $(i, j)$, pay cost $A_{i, j}$, and change that cell to white.

**Step 3**
Place the piece on the cell specified as the initial position in Step 1. Then, starting with Alice, Alice and Bob take turns making moves.
* On Alice's turn, Alice moves the piece to an adjacent cell to the **left** or **right**.
* On Bob's turn, Bob moves the piece to an adjacent cell in any of the **up**, **down**, **left**, or **right** directions.

A move that would take the piece outside the grid is not allowed.
Step 3 ends immediately after Alice and Bob have each taken $10^{10}$ turns.
At the end of Step 3, if the piece is on a white cell, Alice wins; if it is on a black cell, Bob wins. In Step 3, Alice and Bob each act optimally to win.

For each cell $(h, w)$, find the minimum total cost that Alice must pay in Step 2 to guarantee a win if $(h, w)$ is specified as the initial cell in Step 1.
$T$ test cases are given; solve each of them.

## Constraints
* $1 \le T \le 10^4$
* $2 \le N \le 500$
* $0 \le A_{i,j} \le 10^9$
* All input values are integers.
* The sum of $N^2$ over all test cases is at most $500^2$.

## Input
The input is given from Standard Input in the following format:
```text
T
case_1
case_2
:
case_T

```

Each test case is given in the following format:

```text
N
A_{1,1} A_{1,2} ... A_{1,N}
A_{2,1} A_{2,2} ... A_{2,N}
:
A_{N,1} A_{N,2} ... A_{N,N}

```

## Output

Output $N$ lines per test case.  
For each test case, the $h$-th line should contain the minimum total cost that Alice must pay in Step 2 to guarantee a win for each of $(h, 1), (h, 2), \dots, (h, N)$ specified as the initial cell, space-separated.

## Examples:
### Example 1:
**Sample Input:**
```
3
2
1 4
3 2
3
1 2 3
8 9 4
7 6 5
4
0 0 1 0
1 0 1 1
1 1 1 0
0 1 1 1
```
**Sample Output:**
```
3 7
7 3
25 20 25
20 25 20
25 20 25
4 3 4 3
4 4 3 5
4 3 4 3
3 4 3 5
```
**Explaination:**  
Let us explain the first test case.  
For $(h, w) = (1, 1)$ or $(h, w) = (2, 2)$, Alice changes cells $(1, 1)$ and $(2, 2)$ to white.  
In this case, at the end of each of Bob's turns, the piece is at $(1, 1)$ or $(2, 2)$. Therefore, immediately after Alice and Bob have each taken $10^{10}$ turns, the piece is at $(1, 1)$ or $(2, 2)$, so Alice wins regardless of how the piece is moved. The cost Alice pays in Step 2 is $A_{1,1} + A_{2,2} = 1 + 2 = 3$.  
For $(h, w) = (1, 2)$ or $(h, w) = (2, 1)$, it can be verified that Alice can win by changing cells $(1, 2)$ and $(2, 1)$ to white. In this case, the cost Alice pays in Step 2 is $A_{1,2} + A_{2,1} = 4 + 3 = 7$.
