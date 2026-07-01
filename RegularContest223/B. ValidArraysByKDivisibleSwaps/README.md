# B - Valid Arrays by K-Divisible Swaps
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:
You are given an integer sequence $A$ of length $N$ and a positive integer $K$.  
You can perform the following operation on $A$ any number of times:

* Choose an integer $i$ with $1 \le i \le N - 1$ such that $A_i + A_{i+1}$ is divisible by $K$, and swap $A_i$ and $A_{i+1}$.

Find the total number, modulo 998244353, of distinct sequences that $A$ can become after performing the operation zero or more times.

Solve $T$ test cases per input.

## Constraints

* $1 \le T \le 10^5$
* $2 \le N \le 2 \times 10^5$
* $1 \le K \le 10^9$
* $1 \le A_i \le 10^9$
* The sum of $N$ over all test cases is at most $2 \times 10^5$.
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

Each test case $\text{case}_t$ is given in the following format:
```
N K
A_1 A_2 ... A_N
```

## Output

Output the answers over a total of $T$ lines. The $t$-th line should contain the answer for the $t$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
3
4 3
1 2 4 7
6 4
1 5 3 6 2 4
3 2
2 2 3
```
**Sample Output:**
```
4
6
1
```
**Explaination:**  
For the first test case, the sequences that $A$ can become after performing the operation zero or more times are these four:
$(1, 2, 4, 7), (1, 4, 2, 7), (1, 4, 7, 2), (2, 1, 4, 7)$.
