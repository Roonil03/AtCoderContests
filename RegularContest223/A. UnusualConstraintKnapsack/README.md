# A - Unusual-Constraint Knapsack

### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 400 points

## Description:
There are $N$ items $1, 2, \dots, N$.  
Item $i$ has weight $w_i$ and value $v_i$.
For $i = 2, 3, \dots, N$, the following holds:
* $\sum_{j=1}^{i-1} w_j < w_i$

Choose some (possibly zero) items such that the total weight is at most $W$.  
Find the maximum possible total value of the chosen items.  
Solve $T$ test cases per input.

## Constraints
* $1 \le T \le 2 \times 10^5$
* $1 \le N \le 60$
* $1 \le w_i \le W \le 10^{18}$
* $\sum_{j=1}^{i-1} w_j < w_i$ ($2 \le i \le N$)
* $1 \le v_i \le 10^{16}$
* The sum of $N$ over all test cases is at most $2 \times 10^5$.
* All input numbers are integers.

## Input
The input is given from Standard Input in the following format:
```
T
case_1
case_2
:
case_T
```

Each test case $\text{case}_t$ is given in the following format:
```
N W
w_1 v_1
w_2 v_2
:
w_N v_N
```

## Output
Output the answers over a total of $T$ lines. The $t$-th line should contain the answer for the $t$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
3
3 10
1 2
3 1
9 3
3 20
1 2
3 1
9 3
4 15
1 1
3 2
5 3
10 4
```
**Sample Output:**
```
5
6
7
```
**Explaination:**  
For the first test case, choosing items 1 and 3 gives a total weight of 10 and a total value of 5.  
Moreover, it is impossible to achieve a total value of 6 or more while satisfying the condition.

