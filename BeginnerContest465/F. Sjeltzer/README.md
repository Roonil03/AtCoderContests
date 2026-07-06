# F - Sjeltzer?
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 525 points

## Description:
A refrigerator stores $N$ drinks. Each drink has a 6-digit numeric ID $S_i$ and a size $V_i$. All $S_1, \dots, S_N$ are distinct.

You are tasked with answering $Q$ queries. Each query is given as two 6-digit numeric strings $x$ and $y$. For each query, find the sum of the sizes ($V_i$) of all drinks whose ID $s$ satisfies the following condition for every $k \in \{1, \dots, 6\}$:
$$x_k \leq s_k \leq y_k$$
where $s_k, x_k, y_k$ denote the integer values of the $k$-th digits of strings $s, x,$ and $y$ respectively.

## Constraints
* $1 \leq N \leq 3 \times 10^5$
* $S_i$ is a 6-digit numeric string.
* $1 \leq V_i \leq 10^9$
* $1 \leq Q \leq 3 \times 10^5$
* $|x| = |y| = 6$

## Input Format
```
N
S_1 V_1
...
S_N V_N
Q
x_1 y_1
...
x_Q y_Q
```

## Output Format
Output $Q$ lines, where the $q$-th line contains the answer to the $q$-th query.

## Examples:
### Example 1:
**Sample Input:**
```
5
000000 1
314159 2
161803 10
169231 5
384400 20
4
150001 269944
302010 396939
000000 999999
999000 000444
```
**Sample Output:**
```
15
0
38
0
```
**Explaination:**  
For the first query, the drinks satisfying the condition are the third and fourth drinks.

For the second query, no drinks satisfy the condition.

For the third query, the drinks satisfying the condition are the first, second, third, fourth, and fifth drinks.

For the fourth query, no drinks satisfy the condition.

### Example 2:
**Sample Input:**
```
8
778722 12744734
488742 359266786
955942 335004463
454854 331175626
934246 179761526
927777 657312747
652568 109900930
753279 405123850
8
201000 785589
202325 955898
310401 875947
044023 988999
111230 567897
133241 577989
101033 999499
453013 796988
```
**Sample Output:**
```
515024780
109900930
0
331175626
331175626
331175626
584885376
331175626
```
