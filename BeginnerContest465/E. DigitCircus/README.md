# E - Digit Circus
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 450 points

## Description:
Find, modulo $998244353$, the number of integers $x$ with $1 \leq x \leq N$ that satisfy **exactly one** of the following three conditions:

1.  $x$ is a multiple of $3$.
2.  The decimal representation of $x$ contains the digit `3`.
3.  Exactly three different digits are used in the decimal representation of $x$.

*Note: The decimal representation of an integer should not have unnecessary leading zeros.*

## Constraints
* $N$ is an integer.
* $1 \leq N < 10^{500}$

## Input Format
The input is given from Standard Input in the following format:
```
N
```

## Output Format
Output the calculated count modulo $998244353$.

## Examples:
### Example 1:
**Sample Input:**
```
45
```
**Sample Output:**
```
19
```
**Explanation:**  
Among the integers from $1$ to $45$, there are 19 integers satisfying exactly one of the conditions:
* **Condition 1 only:** 10 integers ($6, 9, 12, 15, 18, 21, 24, 27, 42, 45$).
* **Condition 2 only:** 9 integers ($13, 23, 31, 32, 34, 35, 37, 38, 43$).
* **Condition 3 only:** 0 integers.

### Example 2:
**Sample Input:**
```
1013
```
**Sample Output:**
```
424
```
**Explaination:**  
* Satisfying only condition 1: `555`, `1011`.
* Satisfying only condition 2: `343`, `553`.
* Satisfying only condition 3: `1012`, `704`.

### Example 3:
**Sample Input:**
```
2
```
**Sample Output:**
```
0
```
**Explaination:**  
There are no applicable integers.

### Example 4:
**Sample Input:**
```
314159265358979323846264338327950
```
**Sample Output:**
```
658111391
```

