# G - Random Walk Distance
### Time Limit: 3 sec / Memory Limit: 1024 MiB

## Score : 600 points

## Description:
You are given a positive integer $N$ and an integer $X$. Takahashi starts at coordinate $0$ on a number line and performs the following move $N$ times:
* When at coordinate $x$, choose coordinate $x - 1$ or coordinate $x + 1$ with equal probability and move there.

The choices for each of the $N$ moves are independent. Let $x'$ be the coordinate after all $N$ moves. Find the expected value of $|x' - X|$, modulo 998244353. You are given $T$ test cases.

### Definition of Expected Value Modulo 998244353
The sought expected value is a rational number. When expressed as an irreducible fraction $\frac{P}{Q}$, the answer is the unique integer $R$ such that $R \times Q \equiv P \pmod{998244353}$ and $0 \le R < 998244353$.

## Constraints
* $1 \le T \le 2 \times 10^5$
* $1 \le N \le 2 \times 10^5$
* $|X| \le 2 \times 10^5$
* All input values are integers.

## Input Format
The input is provided from Standard Input in the following format:
```text
T
case1
case2
:
caseT

```

Each `case_i` is the $i$-th test case, given as:

```text
N X

```

## Output Format

Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
5
3 2
6 4
2026 -620
12345 67890
98765 -43210
```
**Sample Output:**
```
748683267
935854085
270602660
67890
844852181
```
**Explaination:**  
For the first test case, Takahashi ends up at coordinate:
* $-3$ with probability $\frac{1}{8}$
* $-1$ with probability $\frac{3}{8}$
* $1$ with probability $\frac{3}{8}$
* $3$ with probability $\frac{1}{8}$

Thus, the expected value of $|x' - X|$ is:
$\frac{1}{8} \cdot |-3 - 2| + \frac{3}{8} \cdot |-1 - 2| + \frac{3}{8} \cdot |1 - 2| + \frac{1}{8} \cdot |3 - 2| = \frac{9}{4}$.