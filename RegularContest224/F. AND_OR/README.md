# F - AND/OR
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 700 points

## Description:
You are given a length-$N$ sequence of non-negative integers $A = (A_1, A_2, \dots, A_N)$ and an integer $K$.

Initially, $x = 0$. For $i = 1, 2, \dots, N$ in this order, let us choose one of the following two operations to perform.
* Operation 1 : Replace $x$ with $x$ AND $A_i$.
* Operation 2 : Replace $x$ with $x$ OR $A_i$.

Here, operation 2 must be chosen at most $K$ times in total. AND denotes the bitwise AND operation, and OR denotes the bitwise OR operation.

Let $M$ be the maximum possible value of $x$ after all operations are finished. Find the number, modulo 998244353, of operation sequences such that the final $x$ equals $M$.

Here, two operation sequences are distinguished if and only if there exists an integer $j$ ($1 \le j \le N$) such that the operation chosen at the $j$-th step differs between them.

$T$ test cases are given; solve each of them.

### What is the bitwise AND operation?
The bitwise AND of non-negative integers $A, B$, denoted $A$ AND $B$, is defined as follows.
* The digit in the $2^k$ ($k \ge 0$) place of the binary representation of $A$ AND $B$ is 1 if the corresponding digits of $A$ and $B$ in binary are both 1, and 0 otherwise.

For example, 3 AND 5 = 1 (in binary: 011 AND 101 = 001).

### What is the bitwise OR operation?
The bitwise OR of non-negative integers $A, B$, denoted $A$ OR $B$, is defined as follows.
* The digit in the $2^k$ ($k \ge 0$) place of the binary representation of $A$ OR $B$ is 1 if at least one of the corresponding digits of $A$ and $B$ in binary is 1, and 0 otherwise.

For example, 3 OR 5 = 7 (in binary: 011 OR 101 = 111).

## Constraints
* $1 \le T \le 10^4$
* $1 \le K \le N \le 2 \times 10^5$
* $0 \le A_i < 2^{60}$
* The sum of $N$ in each input is at most $2 \times 10^5$.
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
N K
A_1 A_2 ... A_N
```

## Output
Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
5
5 3
3 7 1 2 6
1 1
1
10 8
3 1 4 1 5 9 2 6 5 3
10 5
227966327241983404 430356836747706085 918791034668488208 753980266897555955 1090352658151595591 1077218377572152409 641276315925917062 859382256805178767 103741332934325112 1090530740094421349
33 33
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
**Sample Output:**
```
3
1
26
1
603979768
```
**Explaination:**  
This input contains five test cases.

For the first test case, $M = 7$, and the following three operation sequences achieve the final value $x = M$.
* Perform the operations in the order 1, 1, 2, 2, 2. $x$ changes as 0 $\to$ 0 $\to$ 0 $\to$ 1 $\to$ 3 $\to$ 7.
* Perform the operations in the order 1, 2, 1, 2, 2. $x$ changes as 0 $\to$ 0 $\to$ 7 $\to$ 1 $\to$ 3 $\to$ 7.
* Perform the operations in the order 2, 1, 1, 2, 2. $x$ changes as 0 $\to$ 3 $\to$ 3 $\to$ 1 $\to$ 3 $\to$ 7.

For the fifth test case, note that the answer should be output modulo 998244353.