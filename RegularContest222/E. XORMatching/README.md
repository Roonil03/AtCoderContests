# E - XOR Matching
### Time Limit: 3 sec / Memory Limit: 1024 MiB

## Score : 700 points

## Description:
There are $N$ cards. The $i$-th card ($1 \le i \le N$) has the integer $A_i$ written on it. Here, $0 \le A_i \le 2^M - 1$ holds.

For each integer $X = 0, 1, \dots, 2^M - 1$, let $f(X)$ denote the answer to the following problem:
* Consider forming some pairs of cards.
* Each pair consists of two distinct cards, and the bitwise XOR of the integers written on those two cards must equal $X$. The same card cannot be included in multiple pairs.
* Find the maximum number of pairs that can be formed under these conditions.

Output the following value:
$$\left( \sum_{X=0}^{2^M - 1} f(X) \times 10^X \right) \mod 998244353$$

### What is the bitwise XOR operation
The bitwise XOR of non-negative integers $A, B$, $A \oplus B$, is defined as follows:
* The digit at the $2^k$ ($k \ge 0$) place of $A \oplus B$ in binary representation is 1 if exactly one of the digits at the $2^k$ place of $A$ and $B$ in binary representation is 1, and 0 otherwise.

For example, $3 \oplus 5 = 6$ (in binary: $011 \oplus 101 = 110$).
In general, the bitwise XOR of $k$ non-negative integers $p_1, p_2, p_3, \dots, p_k$ is defined as $(\dots((p_1 \oplus p_2) \oplus p_3) \oplus \dots \oplus p_k)$, and it can be proved that this does not depend on the order of $p_1, p_2, p_3, \dots, p_k$.

## Constraints
* $2 \le N \le 2 \times 10^5$
* $1 \le M \le 20$
* $0 \le A_i \le 2^M - 1$ ($1 \le i \le N$)
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```text
N M
A_1 A_2 ... A_N

```

## Output

Output the following value:

$$\left( \sum_{X=0}^{2^M - 1} f(X) \times 10^X \right) \mod 998244353$$

## Examples:
### Example 1:
**Sample Input:**
```
4 2
1 1 3 3
```
**Sample Output:**
```
202
```
**Explaination:**  

* For $X = 0$: two pairs $(A_1, A_2)$ and $(A_3, A_4)$ can be formed.
* For $X = 1$: zero pairs can be formed.
* For $X = 2$: two pairs $(A_1, A_4)$ and $(A_2, A_3)$ can be formed.
* For $X = 3$: zero pairs can be formed.

Therefore, $f(0) = 2, f(1) = 0, f(2) = 2,$ and $f(3) = 0$. The value to be output is $2 \times 1 + 0 \times 10 + 2 \times 100 + 0 \times 1000 = 202$.

### Example 2:
**Sample Input:**
```
10 3
5 2 1 4 5 5 5 0 1 7
```
**Sample Output:**
```
22332223
```
### Example 3:
**Sample Input:**
```
10 4
11 6 3 8 6 7 14 10 10 11
```
**Sample Output:**
```
613668597
```
