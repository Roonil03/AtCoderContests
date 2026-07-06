# D - X to Y
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 400 points

## Description:
You are given integers $X, Y,$ and an integer $K$ ($K \geq 2$). Starting with a variable $x = X$, you can perform the following operation zero or more times:
* Choose an integer $y$ such that $\lfloor \frac{x}{K} \rfloor = y$ or $\lfloor \frac{y}{K} \rfloor = x$, and replace the current value of $x$ with $y$.

Find the minimum number of operations required to transform $x$ into $Y$. It is guaranteed that $Y$ is always reachable from $X$.

## Constraints
* $1 \leq T \leq 2 \times 10^5$
* $0 \leq X, Y \leq 10^{18}$
* $2 \leq K \leq 10^{18}$

## Input Format
The first line contains $T$ (number of test cases). Each test case consists of a single line containing:

```
X Y K
```

## Output Format
Output the minimum number of operations for each test case on a new line.


## Examples
### Example 1:
**Sample Input:**
```
4
11 9 3
0 0 2
842 180 7
1948706013487601 48019760148910476 89014537
```
**Sample Output:**
```
2
0
7
5
```
**Explaination:**  
$x = 11, Y = 9, K = 3$.  
To reach 9 from 11 in two operations:
1. Choose $y = 3$. Since $\lfloor \frac{11}{3} \rfloor = 3$, this is valid. New $x = 3$.
2. Choose $y = 9$. Since $\lfloor \frac{9}{3} \rfloor = 3$, this is valid. New $x = 9$.
The minimum operations required is 2.
