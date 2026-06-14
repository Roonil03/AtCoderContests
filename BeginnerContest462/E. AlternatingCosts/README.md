# E - Alternating Costs
### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 450 points

## Description:
You are given integers $A, B, X, Y$.

A piece is placed on a two-dimensional plane. Initially, the piece is at coordinate $(0, 0)$.

You can perform the following operation zero or more times:
* Let the current coordinate of the piece be $(x, y)$. Move the piece to one of the coordinates $(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)$.

The cost of the $k$-th operation ($k \ge 1$) depends on the parity of $k$, as follows:
* If $k$ is odd: Let the current coordinate of the piece be $(x, y)$. The cost of moving to $(x - 1, y)$ or $(x + 1, y)$ is $A$, and the cost of moving to $(x, y - 1)$ or $(x, y + 1)$ is $B$.
* If $k$ is even: Let the current coordinate of the piece be $(x, y)$. The cost of moving to $(x - 1, y)$ or $(x + 1, y)$ is $B$, and the cost of moving to $(x, y - 1)$ or $(x, y + 1)$ is $A$.

Find the minimum total cost required to move the piece to coordinate $(X, Y)$.

$T$ test cases are given; solve each one.

## Constraints
* $1 \le T \le 2 \times 10^5$
* $1 \le A, B \le 10^9$
* $-10^9 \le X, Y \le 10^9$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:

```text
T
case_1
case_2
:
case_T
```
The $i$-th ($1 \le i \le T$) test case is given in the following format:

```text
A  B  X  Y

```

## Output

Output the answers for the test cases in order, each on a separate line.

## Examples:
### Example 1:
**Sample Input:**
```
5
1 2 -1 2
8 5 0 0
7 13 9 4
1 1 0 100
31 9 -74 -60
```
**Sample Output:**
```
4
0
103
100
1332
```
**Explaination:**  
Consider the first test case.
The following moves cost 4 in total:

* Move the piece from $(0, 0)$ to $(-1, 0)$. This costs 1.
* Move the piece from $(-1, 0)$ to $(-1, 1)$. This costs 1.
* Move the piece from $(-1, 1)$ to $(-1, 2)$. This costs 2.

It is impossible to move the piece to $(-1, 2)$ with a total cost less than 4, so output 4 on the first line.
