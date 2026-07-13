# E - ABC|AB|A
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:
You are given a string $S$ consisting of A, B, and C.

You can perform the following operation zero or more times.
* Choose a substring (contiguous subsequence) of $S$ that is A, AB, or ABC, and delete it. The remaining characters are concatenated, preserving their order.

Find the minimum possible length of $S$ in the end.

$T$ test cases are given; solve each of them.

## Constraints
* $T$ is an integer between 1 and $10^5$, inclusive.
* $S$ is a string consisting of A, B, and C with length between 1 and $10^6$, inclusive.
* The sum of $|S|$ in each input is at most $10^6$.

## Input
The input is given from Standard Input in the following format, where case$_i$ denotes the $i$-th test case:
```
T
case_1
case_2
:
case_T
```

Each test case is given in the following format:
```
S
```

## Output
Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
5
CAABCB
B
AAABBC
AABBCC
CABCCBCBAABCBBBAABAABACABBC
```
**Sample Output:**
```
1
1
0
1
7
```
**Explaination:**  
This input contains five test cases.

For the first test case, we can perform the operations as follows, for example.
* Choose and delete the third through fifth characters of S = CAABCB. After the operation, S becomes CAB.
* Choose and delete the second through third characters of S = CAB. After the operation, S becomes C.
* No further operations can be performed. S = C has length 1, which is the minimum achievable.