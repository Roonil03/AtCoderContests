# G - Celester 2
### Time Limit: 3 sec / Memory Limit: 1024 MiB

## Score : 625 points

## Description:
The weather for the upcoming $N$ days is given as a string $S$.
If the $i$-th character of $S$ is `S`, then the weather on day $i$ is sunny; if it is `R`, then the weather on day $i$ is rainy.

You can perform the following operation between $0$ and $k$ times, inclusive:

* Choose an integer $i$ with $1 \le i \le N$.
* If the weather on day $i$ is sunny, change it to rainy; if it is rainy, change it to sunny.

After performing the operations, you gain happiness based on the final weather according to the following condition:

* For each integer $i$ with $1 \le i \le N - 1$, if the weather on day $i$ after modification is rainy and the weather on day $i + 1$ is sunny, your happiness increases by $1$.

For each $k = 0, 1, \dots, N$, find the maximum total happiness you can gain by performing the operation at most $k$ times.

$T$ test cases are given; solve each.

## Constraints

* $1 \le T \le 10^4$
* $N$ is an integer between 2 and $10^6$, inclusive.
* $S$ is a string of length $N$ consisting of `S` and `R`.
* The sum of $N$ in a single input is at most $10^6$.

## Input

The input is given from Standard Input in the following format, where $\text{case}_i$ denotes the $i$-th test case:
```
T
case_1
case_2
:
case_T
```

Each test case is given in the following format:
```
N
S
```

## Output

Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

For each test case, let $A_i$ be the answer for $k = i$. Then, output the answer in the following format:

```
A_0 A_1 ... A_N
```

## Examples:
### Example 1:
**Sample Input:**
```
5
4
SSSR
2
SR
6
RSRSRS
10
RSRSRRRRRR
20
SSRRSSSSRRRSSRRSRSRS
```
**Sample Output:**
```
0 1 1 2 2
0 0 1
3 3 3 3 3 3 3
2 3 4 5 5 5 5 5 5 5 5
5 6 7 8 8 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10
```
**Explaination:**  
This input contains five test cases.

For the 1st test case:
* The weather on each day before any operations is sunny, sunny, sunny, rainy in order.
* For $k = 0$, no operations can be performed.
    * The weather on each day after operations is sunny, sunny, sunny, rainy, and the total happiness is 0, which is the achievable maximum.
* For $k = 1$, for example, changing the weather on day 2 is optimal.
    * The weather on each day after operations is sunny, rainy, sunny, rainy, and the total happiness is 1, which is the achievable maximum.
* For $k = 2$, for example, changing the weather on days 1 and 2 is optimal.
    * The weather on each day after operations is rainy, rainy, sunny, rainy, and the total happiness is 1, which is the achievable maximum.
* For $k = 3$, for example, changing the weather on days 1, 3, and 4 is optimal.
    * The weather on each day after operations is rainy, sunny, rainy, sunny, and the total happiness is 2, which is the achievable maximum.
* For $k = 4$, for example, changing the weather on days 1, 3, and 4 is optimal.
    * The weather on each day after operations is rainy, sunny, rainy, sunny, and the total happiness is 2, which is the achievable maximum.

