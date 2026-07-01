# C - Whole Product of Pairwise Distances
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:
You are given a sequence $A$ of $N$ positive integers.  
Find the remainder when $\prod_{1 \le i < j \le N} |A_i - A_j|$ is divided by $N$.

Solve $T$ test cases per input.

## Constraints
* $1 \le T \le 10^5$
* $2 \le N \le 2 \times 10^5$
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
N
A_1 A_2 ... A_N
```

## Output

Output the answers over a total of $T$ lines. The $t$-th line should contain the answer for the $t$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
3
3
1 9 5
3
2 2 3
5
11 33 22 55 44
```
**Sample Output:**
```
2
0
3
```
**Explaination:**  
For the first test case, $|A_1 - A_2| \times |A_1 - A_3| \times |A_2 - A_3| = 8 \times 4 \times 4 = 128$, and the remainder when this is divided by 3 is 2.
