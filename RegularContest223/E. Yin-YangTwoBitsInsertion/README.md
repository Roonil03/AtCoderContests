# E - Yin-Yang Two Bits Insertion
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 700 points

## Description:
You are given integer sequences $A = (A_1, A_2, \dots, A_N)$ and $B = (B_1, B_2, \dots, B_M)$ of length 2 or more, consisting of 0s and 1s.  
You can perform the following operation on $A$ any number of times:

* Choose an integer $i$ satisfying $1 \le i \le |A| - 1$.
* Insert $1 - A_i$ and $1 - A_{i+1}$ in this order between $A_i$ and $A_{i+1}$.

Determine whether it is possible to make $A$ equal to $B$.

Solve $T$ test cases per input.

## Constraints
* $1 \le T \le 10^5$
* $2 \le N \le M \le 2 \times 10^5$
* $A_i, B_i \in \{0, 1\}$
* The sum of $N + M$ over all test cases is at most $4 \times 10^5$.
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

Each test case $\text{case}_t$ is given in the following format:
```
N M
A_1 A_2 ... A_N
B_1 B_2 ... B_M
```

## Output
Output the answers over a total of $T$ lines. The $t$-th line should contain `Yes` if it is possible to make $A$ equal to $B$ for the $t$-th test case, and `No` otherwise.

## Examples:
### Example 1:
**Sample Input:**
```
3
3 7
0 1 1
0 1 0 1 1 0 1
2 4
0 1
0 1 0 1
3 4
0 0 0
0 0 0 1
```
**Sample Output:**
```
Yes
Yes
No
```
**Explaination:**  
For the first test case, initially $A = (0, 1, 1)$.  
First, choosing $i = 2$ gives $A = (0, 1, 0, 0, 1)$.  
Next, choosing $i = 3$ gives $A = (0, 1, 0, 1, 1, 0, 1)$.  

