# F - Triple Transformation
### Time Limit: 3 sec / Memory Limit: 1024 MiB

## Score : 700 points

## Description:
Consider an **operation** on a triple $(x, y, z)$ of non-negative integers. In the operation, $(x, y, z)$ is replaced according to the following rules:
* If $y + z < x$: replace with $(x - y - z, 2y, 2z)$.
* If $x + z < y$: replace with $(2x, y - x - z, 2z)$.
* If $x + y < z$: replace with $(2x, 2y, z - x - y)$.
* If none of the above conditions hold: replace with $(y + z - x, x + z - y, x + y - z)$.

Note that every triple of non-negative integers falls into exactly one of the above four cases.

You are given non-negative integers $A_1, A_2, A_3, B_1, B_2, B_3$. Consider performing the operation on the triple $(A_1, A_2, A_3)$ zero or more times to obtain $(B_1, B_2, B_3)$. Find the minimum number of operations required to do so. If it is impossible to obtain $(B_1, B_2, B_3)$ no matter how many times the operation is performed, output -1.

$T$ test cases are given; solve each of them.

## Constraints
* $1 \le T \le 300$
* $0 \le A_1, A_2, A_3, B_1, B_2, B_3 \le 10^8$
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

Each test case is given in the following format:

```
A_1 A_2 A_3 B_1 B_2 B_3

```

## Output

Output one line per test case.

For each test case, output the minimum number of operations required to obtain $(B_1, B_2, B_3)$ by performing the operation on the triple $(A_1, A_2, A_3)$ zero or more times. If it is impossible to obtain $(B_1, B_2, B_3)$ no matter how many times the operation is performed, output -1.

## Examples:
### Example 1:
**Sample Input:**
```
6
2 3 4 2 3 4
2 3 4 5 3 1
2 3 4 1 6 2
2 3 4 4 3 2
1 0 0 0 0 1
0 0 0 0 0 0
```
**Sample Output:**
```
0
1
2
-1
-1
0
```
**Explaination:**  
For $(A_1, A_2, A_3) = (2, 3, 4)$, the triple changes as follows when the operation is repeatedly applied:

* $(2, 3, 4) \to (5, 3, 1) \to (1, 6, 2) \to (2, 3, 4) \to (5, 3, 1) \to (1, 6, 2) \to \cdots$

From this, we can see that the answers to the first three test cases are 0, 1, 2.
