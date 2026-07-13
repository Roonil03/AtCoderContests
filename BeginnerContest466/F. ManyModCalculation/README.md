# F - Many Mod Calculation
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:
You are given integers $N, X$ and a length-$N$ sequence of positive integers $A = (A_1, A_2, \dots, A_N)$.

For a non-negative integer $x$, define $f(x) = (\dots((x \bmod A_1) \bmod A_2) \dots) \bmod A_N$.
Find the number of integers $x$ between 1 and $X$, inclusive, such that $f(x) = 0$.

You are given $T$ test cases; solve each of them.

## Constraints
* $1 \le T \le 2 \times 10^5$
* $1 \le N \le 2 \times 10^5$
* The sum of $N$ over all test cases is at most $2 \times 10^5$.
* $1 \le X \le 10^{18}$
* $1 \le A_i \le 10^{18}$
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
A_1 A_2 ... A_N
```

## Output
Output the answers for the test cases in order, separated by newlines.

## Examples:
### Example 1:
**Sample Input:**
```
4
3 7
5 2 3
9 31415
9 9 8 2 4 4 3 5 3
1 1000000000000000000
1
9 20260405
3141 5926 5358 9793 2384 6264 3383 2795 288
```
**Sample Output:**
```
4
17452
1000000000000000000
77403
```
**Explaination:**  
Consider the first test case.

For example, when $x = 7, f(7) = (((7 \bmod 5) \bmod 2) \bmod 3) = (2 \bmod 2) \bmod 3 = 0 \bmod 3 = 0$.

There are four integers $x$ between 1 and 7 such that $f(x) = 0: x = 2, 4, 5, 7$.