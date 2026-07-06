# G - Sum of Mex of Mod of Linear
### Time Limit: 3 sec / Memory Limit: 1024 MiB

## Score : 625 points

## Description:
You are given integers $N, M, C, K$ and an integer sequence $A = (A_1, A_2, \dots, A_N)$ of length $N$. 

You must process $Q$ queries in order. The $q$-th query $(1 \leq q \leq Q)$ provides integers $i_q$ and $X_q$. You must update $A_{i_q}$ to $X_q$ and then calculate the following value:

$$\sum_{k=0}^{K-1} \text{mex}_{1 \leq i \leq N} \{(Ck + A_i) \pmod M\}$$

Where $\text{mex}_{1 \leq i \leq N} B_i$ denotes the smallest non-negative integer not contained in the sequence $B = (B_1, B_2, \dots, B_N)$.

## Constraints
* $1 \leq N \leq 2 \times 10^5$
* $0 \leq C < M \leq 10^9$
* $1 \leq K \leq 10^9$
* $0 \leq A_i < M$
* $1 \leq Q \leq 2 \times 10^5$
* $1 \leq i_q \leq N$
* $0 \leq X_q < M$

## Input Format
```
N M C K
A_1 A_2 ... A_N
Q
i_1 X_1
i_2 X_2
...
i_Q X_Q
```

## Output Format
Output $Q$ lines. The $q$-th line should contain the answer to the problem after processing the $q$-th query.


## Example
### Example 1:
**Sample Input:**
```
2 3 1 2
0 2
3
2 2
1 1
2 1
```
**Sample Output:**
```
3
1
0
```
**Explaination:**  
* **First query:** $A$ becomes $(0, 2)$. Calculation: $\text{mex}(\{0, 2\}) + \text{mex}(\{(0+0)\pmod 3, (2+1)\pmod 3\}) = \text{mex}(\{0, 2\}) + \text{mex}(\{0, 0\}) = 1 + 2 = 3$.
* **Second query:** $A$ becomes $(1, 2)$. Calculation: $\text{mex}(\{1, 2\}) + \text{mex}(\{(1+0)\pmod 3, (2+1)\pmod 3\}) = \text{mex}(\{1, 2\}) + \text{mex}(\{1, 0\}) = 0 + 1 = 1$.
* **Third query:** $A$ becomes $(1, 1)$. Calculation: $\text{mex}(\{1, 1\}) + \text{mex}(\{(1+0)\pmod 3, (1+1)\pmod 3\}) = \text{mex}(\{1, 1\}) + \text{mex}(\{1, 2\}) = 0 + 0 = 0$.

### Example 2:
**Sample Input:**
```
7 9 3 19
7 0 2 8 1 3 4
7
3 5
1 6
3 2
5 5
4 7
7 8
2 4
```
**Sample Output:**
```
32
44
53
37
49
37
54
```