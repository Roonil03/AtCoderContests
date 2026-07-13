# B - Representative Balls
### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 200 points
### Description:
There are $N$ balls.
The color of the $i$-th ball is $C_i$, and its size is $S_i$. Here, the colors are represented by integers $1, 2, \dots, M$.
For $k = 1, 2, \dots, M$, output the maximum size of a ball of color $k$, or -1 if there is no ball of color $k$.

## Constraints
* $1 \le N, M \le 100$
* $1 \le C_i \le M$
* $1 \le S_i \le 100$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
N M
C_1 S_1
C_2 S_2
:
C_N S_N
```

## Output
In the order $k = 1, 2, \dots, M$, output the maximum size of a ball of color $k$ if such a ball exists, or -1 otherwise, separated by spaces.

## Examples:
### Example 1:
**Sample Input:**
```
4 5
1 3
2 10
1 7
4 9
```
**Sample Output:**
```
7 10 -1 9 -1
```
**Explaination:**  
The maximum size of a ball of color 1 is 7, that of a ball of color 2 is 10, and that of a ball of color 4 is 9.

There is no ball of color 3 or color 5.

### Example 2:
**Sample Input:**
```
5 5
2 6
5 12
5 2
5 9
2 7
```
**Sample Output:**
```
-1 7 -1 -1 12
```
