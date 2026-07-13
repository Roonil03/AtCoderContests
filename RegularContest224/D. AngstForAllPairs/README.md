# D - Angst for All Pairs
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:
There are $N$ cards, numbered 1 through $N$. Initially, nothing is written on any of the cards.

You can write zero or more positive integers on each card.

The cost of writing a positive integer $k$ once is equal to the number of digits in the decimal representation of $k$.

Determine whether it is possible to satisfy the following condition. If it is possible, output the minimum total cost required; if it is not possible, output $-1$.

* For every pair of positive integers $(x, y)$ satisfying $1 \le x < y \le K$, there exists a card containing exactly one of $x$ and $y$.

$T$ test cases are given; solve each of them.

## Constraints
* $1 \le T \le 10^5$
* $1 \le N \le 10^6$
* $2 \le K \le 10^6$
* The sum of $N$ in each input is at most $10^6$.
* The sum of $K$ in each input is at most $10^6$.
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
```

## Output
Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
4
3 5
100 25
5 1225
180 998244
```
**Sample Output:**
```
5
39
-1
17655598
```
**Explaination:**  
This input contains four test cases.

For the first test case, writing as follows satisfies the condition with a total cost of 5.
* Write 1, 5 on card 1.
* Write 2, 5 on card 2.
* Write 3 on card 3.

For the second test case, the minimum total cost required to satisfy the condition is 39.

For the third test case, it is impossible to satisfy the condition, so output -1.

For the fourth test case, the minimum total cost required to satisfy the condition is 17655598.