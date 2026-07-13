# D - Placing Rooks
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 400 points

## Description:
There is a grid with $N$ rows and $N$ columns.

Initially, nothing is placed on the grid.  
Starting from this state, Takahashi performs $M$ operations on the grid in order. The $i$-th operation ($1 \le i \le M$) is as follows.

* Remove all pieces placed on the cells in the $R_i$-th row from the top.
* Next, remove all pieces placed on the cells in the $C_i$-th column from the left.
* Finally, place a piece on the cell at the $R_i$-th row from the top and the $C_i$-th column from the left.

Output the number of pieces placed on the grid after the $M$ operations.

## Constraints
* $1 \le N \le 3 \times 10^5$
* $1 \le M \le 3 \times 10^5$
* $1 \le R_i \le N$
* $1 \le C_i \le N$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
N M
R_1 C_1
R_2 C_2
:
R_M C_M
```

## Output
Output the number of pieces placed on the grid after the $M$ operations.

## Examples:
### Example 1:
**Sample Input:**
```
3 6
1 1
1 2
3 3
3 2
1 3
1 3
```
**Sample Output:**
```
2
```
**Explaination:**  
Initially, nothing is placed on the grid with three rows and three columns, and pieces are removed and placed by each operation as follows.  
Below, the cell at the $i$-th row from the top and the $j$-th column from the left is denoted as cell $(i, j)$.

* In the first operation, a piece is placed on cell $(1, 1)$.
* In the second operation, the piece is removed from cell $(1, 1)$, and a piece is placed on cell $(1, 2)$.
* In the third operation, a piece is placed on cell $(3, 3)$.
* In the fourth operation, the pieces are removed from cell $(1, 2)$ and cell $(3, 3)$, and a piece is placed on cell $(3, 2)$.
* In the fifth operation, a piece is placed on cell $(1, 3)$.
* In the sixth operation, the piece is removed from cell $(1, 3)$, and a piece is placed on cell $(1, 3)$ again.

In the final state, there is one piece each on cell $(1, 3)$ and cell $(3, 2)$, so output 2.

<img src="https://img.atcoder.jp/abc466/2684b4f61669fe3494512b4b3ac638e3.png"><br>

### Example 2:
**Sample Input:**
```
2 3
1 2
2 1
1 1
```
**Sample Output:**
```
1
```