# C - Not Covered Points

### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 300 points

## Description:
There are $N$ points numbered 1 through $N$ on a two-dimensional plane. Point $i$ ($1 \le i \le N$) has coordinates $(X_i, Y_i)$. Here, it is guaranteed that $X$ and $Y$ are each permutations of $(1, 2, \dots, N)$.

Find the number of values of $i$ such that the interior (not including the boundary) of the rectangle with sides parallel to the $x$-axis and $y$-axis, with lower-left vertex $(0, 0)$ and upper-right vertex $(X_i, Y_i)$, contains none of the $N$ points numbered 1 through $N$.

## Constraints
* $1 \le N \le 3 \times 10^5$
* $1 \le X_i, Y_i \le N$
* $X$ and $Y$ are each permutations of $(1, 2, \dots, N)$.
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
N
X_1  Y_1
X_2  Y_2
:
X_N  Y_N
```

## Output
Output the answer.

## Examples:
### Example 1:
**Sample Input:**
```
3
2 1
1 3
3 2
```
**Sample Output:**
```
2
```
**Explaination:**  
The two values 
i=1,2 satisfy the condition.

For 
i=3, the interior (not including the boundary) of the rectangle with sides parallel to the 
x-axis, with lower-left vertex 
(0,0) and upper-right vertex 
(3,2), contains point 
1.

### Example 2:
**Sample Input:**
```
5
1 1
4 2
2 3
5 5
3 4
```
**Sample Output:**
```
1
```
### Example 3:
**Sample Input:**
```
7
3 4
6 1
5 5
2 7
7 2
1 3
4 6
```
**Sample Output:**
```
2
```
