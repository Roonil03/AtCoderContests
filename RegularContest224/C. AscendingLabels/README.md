# C - Ascending Labels
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:
You are given a connected simple undirected graph with $N$ vertices and $M$ edges. The vertices are numbered $1, 2, \dots, N$, and the $i$-th edge connects vertices $U_i$ and $V_i$.

Construct one integer sequence $A = (A_1, A_2, \dots, A_N)$ satisfying all of the following conditions.
* $0 \le A_v \le N$ for every vertex $v$.
* $A_1 = 0$.
* For every vertex $v$ other than vertex 1, there is exactly one vertex $w$ adjacent to $v$ satisfying $A_w = A_v - 1$.

It can be proved that under the constraints of this problem, there exists at least one integer sequence satisfying all of the above conditions. If there are multiple integer sequences satisfying the conditions, any of them will be accepted.

$T$ test cases are given; solve each of them.

## Constraints
* $1 \le T \le 3 \times 10^4$
* $1 \le N \le 3 \times 10^5$
* $N - 1 \le M \le 3 \times 10^5$
* $1 \le U_i < V_i \le N$
* $(U_i, V_i) \neq (U_j, V_j)$ if $i \neq j$.
* The given graph is connected.
* The sum of $N$ in each input is at most $3 \times 10^5$.
* The sum of $M$ in each input is at most $3 \times 10^5$.
* All input values are integers.

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
N M
U_1 V_1
U_2 V_2
:
U_M V_M
```

## Output
Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

For each test case, output an integer sequence $A$ satisfying the conditions in the following format:
```
A_1 A_2 ... A_N
```

## Examples:
### Example 1:
**Sample Input:**
```
3
6 7
1 5
1 3
3 5
2 5
3 4
3 6
4 6
1 0
6 10
4 6
1 4
2 5
3 6
1 3
1 2
2 3
2 4
3 4
3 5
```
**Sample Output:**
```
0 2 1 2 1 2
0
0 3 2 1 3 3
```
**Explaination:**  
This input contains three test cases.

For the first test case, consider setting $A = (0, 2, 1, 2, 1, 2)$.

* For vertex 1, $A_1 = 0$.
* For vertex 2, there is only one adjacent vertex $w$ satisfying $A_w = A_2 - 1$, which is vertex 5.
* For vertex 3, there is only one adjacent vertex $w$ satisfying $A_w = A_3 - 1$, which is vertex 1.
* For vertex 4, there is only one adjacent vertex $w$ satisfying $A_w = A_4 - 1$, which is vertex 3.
* For vertex 5, there is only one adjacent vertex $w$ satisfying $A_w = A_5 - 1$, which is vertex 1.
* For vertex 6, there is only one adjacent vertex $w$ satisfying $A_w = A_6 - 1$, which is vertex 3.

Thus, this integer sequence $A$ satisfies the conditions in the problem statement.

Additionally, setting $A = (0, 3, 1, 2, 2, 2)$ also satisfies the conditions, so the output 0 3 1 2 2 2 is also accepted.

The figure below shows, for each test case in the sample output, the vertex number $v$ outside each vertex and $A_v$ inside each vertex.

<img src="https://img.atcoder.jp/arc224/b6ddd768f899c66c1c146ba63129d933.png"><br>