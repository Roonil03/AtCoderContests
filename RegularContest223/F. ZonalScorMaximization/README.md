# F - Zonal Score Maximization
### Time Limit: 4 sec / Memory Limit: 1024 MiB
## Score : 800 points

## Description:
Define the score of a positive integer sequence with length 2 or more as the sum of its maximum and minimum values.

For a positive integer sequence $A$ of length 2 or more, let $f(A)$ be the maximum possible value of the total score of the contiguous subsequences when $A$ is divided into one or more contiguous subsequences each of length 2 or more.

More formally, for a positive integer $K$, let $f(A)$ be the maximum possible value of $\sum_{k=1}^{K} (\max(B_k) + \min(B_k))$ when concatenating $K$ positive integer sequences $B_1, B_2, \dots, B_K$, each of length 2 or more, in this order yields the same sequence as $A$.

You are given an integer sequence $Q$ of length $N$ where each element is either an integer between 1 and $N$ inclusive or $-1$, and a positive integer $X$.
Find the total number, modulo 998244353, of permutations $P = (P_1, P_2, \dots, P_N)$ of $(1, 2, \dots, N)$ satisfying all of the following conditions:

* For $i = 1, 2, \dots, N$, if $Q_i \neq -1$ then $P_i = Q_i$.
* $f(P) = X$

Solve $T$ test cases per input.

## Constraints
* $1 \le T \le 10^5$
* $2 \le N \le 10^5$
* $1 \le X \le 10^{18}$
* $Q_i = -1$ or $1 \le Q_i \le N$
* If $Q_i \neq -1$ and $Q_j \neq -1$, then $Q_i \neq Q_j$ ($i \neq j$).
* The sum of $N$ over all test cases is at most $10^5$.
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
T
case_1
case_2
:
case_T
```

Each test case is given in the following format:
```
N X
Q_1 Q_2 ... Q_N
```

## Output
Output the answers over a total of $T$ lines. The $t$-th line should contain the answer for the $t$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
3
3 4
2 -1 -1
4 10
1 3 4 2
9 42
-1 -1 -1 -1 -1 -1 -1 -1 -1
```
**Sample Output:**
```
2
1
155520
```
**Explaination:**  
For the first test case, the permutations P satisfying the first condition are these two: (2,1,3) and (2,3,1). In either case, the only way to divide P into contiguous subsequences each of length 2 or more is to take P itself as a single contiguous subsequence. The total score in that case is 3+1=4, so f(P)=4.  
For the second test case, dividing P=(1,3,4,2) into (1,3) and (4,2) gives a total score of 10, which cannot be exceeded, so f(P) = 10.

