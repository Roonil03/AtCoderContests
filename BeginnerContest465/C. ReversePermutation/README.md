# C - Reverse Permutation
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 300 points

## Description:
You are given an integer $N$ and a string $S$ of length $N$ consisting of 'o' and 'x'. There is an integer sequence $A = (A_1, A_2, \dots, A_N)$ of length $N$, initially set to $A = (1, 2, \dots, N)$.

Perform the following operation on $A$ for $k = 1, 2, \dots, N$ in this order:
* If $S_k =$ 'o', reverse the first $k$ terms of $A$. Specifically, replace $A$ with $(A_k, A_{k-1}, \dots, A_1, A_{k+1}, A_{k+2}, \dots, A_N)$.
* If $S_k =$ 'x', do nothing.

Find the state of $A$ after all operations are completed.

## Constraints
* $2 \leq N \leq 5 \times 10^5$
* $N$ is an integer.
* $S$ is a string of length $N$ consisting of 'o' and 'x'.

## Input Format
```
N
S
```

## Output Format
Output the elements of $A$ after all operations are completed, separated by spaces.


## Examples
### Example 1:
**Sample Input:**
```
5
ooxoo
```
**Sample Output:**
```
5 2 1 3 4
```
**Explaination:**  
$A$ changes as follows with each operation:
* For $k = 1$: Reverse the first 1 term of $A$. $A$ becomes $(1, 2, 3, 4, 5)$.
* For $k = 2$: Reverse the first 2 terms of $A$. $A$ becomes $(2, 1, 3, 4, 5)$.
* For $k = 3$: Do nothing.
* For $k = 4$: Reverse the first 4 terms of $A$. $A$ becomes $(4, 3, 1, 2, 5)$.
* For $k = 5$: Reverse the first 5 terms of $A$. $A$ becomes $(5, 2, 1, 3, 4)$.

### Example 2:
**Sample Input:**
```
7
ooooooo
```
**Sample Output:**
```
7 5 3 1 2 4 6
```

### Example 3:
**Sample Input:**
```
15
xooxoxoxoxoxxoo
```
**Sample Output:**
```
15 11 10 7 6 3 1 2 4 5 8 9 12 13 14
```
