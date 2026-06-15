# D - Shift and Add
### Time Limit: 3 sec / Memory Limit: 1024 MiB

## Score : 700 points

## Description:
Define the **digit sum** of a non-negative integer $n$ as the sum of the digits when $n$ is written in decimal notation. For example, the digit sum of 2026 is $2 + 0 + 2 + 6 = 10$.

You are given positive integer sequences $A = (A_1, A_2, \dots, A_N)$ and $B = (B_1, B_2, \dots, B_N)$.

Using $A$ and $B$, define an integer sequence $X = (X_0, X_1, X_2, \dots, X_N)$ as follows:
* Set $X_0 = 0$.
* For each $i = 1, 2, \dots, N$, choose one of $X_i = 10X_{i-1} + A_i$ and $X_i = 10X_{i-1} + B_i$ to determine $X_i$.

For each $k = 1, 2, \dots, N$, find the minimum possible digit sum of $X_k$.

Solve independently for each $k$. That is, for different $k$, the way to determine the integer sequence $X$ that minimizes the digit sum of $X_k$ may be different.

## Constraints
* $1 \le N \le 20000$
* $1 \le A_i \le 10^9 - 1$
* $1 \le B_i \le 10^9 - 1$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
N
A_1 A_2 ... A_N
B_1 B_2 ... B_N

```

## Output

For $k = 1, 2, \dots, N$, output the minimum possible digit sum of $X_k$, space-separated.

## Examples:
### Example 1:
**Sample Input:**
```
2
123 444
456 222
```
**Sample Output:**
```
6 9
```
**Explaination:**  
The possible integer sequences $X = (X_0, X_1, X_2)$ are the following four:

* $X = (0, 123, 1674)$
* $X = (0, 123, 1452)$
* $X = (0, 456, 5004)$
* $X = (0, 456, 4782)$

The minimum possible digit sum of $X_1$ is 6, which is the digit sum of 123.

The minimum possible digit sum of $X_2$ is 9, which is the digit sum of 5004.
