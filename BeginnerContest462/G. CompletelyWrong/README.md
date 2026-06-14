# G - Completely Wrong
There is a box containing $N$ balls numbered 1 through $N$. Each ball is painted with a color represented as an integer, and ball $i$ is painted with color $C_i$.

Takahashi performed $N$ operations. The $k$-th operation ($1 \le k \le N$) is as follows:
* Draw one ball uniformly at random from the box and discard it. If the drawn ball has color $G_k$, gain 1 point.

Find the probability, modulo 998244353, that the total score over $N$ operations is 0 points.

### Definition of probability modulo 998244353
The probability $P$ is a rational number. You need to output $P \pmod{998244353}$, which is defined as follows:
If $P$ is expressed as an irreducible fraction $P = \frac{x}{y}$, output $x \cdot y^{-1} \pmod{998244353}$, where $y^{-1}$ is the modular multiplicative inverse of $y$ modulo 998244353.

## Constraints
* $1 \le N \le 2 \times 10^5$
* $1 \le C_i, G_k \le N$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:

```text
N
C_1  C_2  ...  C_N
G_1  G_2  ...  G_N

```

## Output

Output the sought probability modulo 998244353.

## Examples:
### Example 1:
**Sample Input:**
```
3
1 2 3
1 1 2
```
**Sample Output:**
```
332748118
```
**Explaination:**  
For example, the operations may proceed as follows:

* First operation: A ball with color 2 is drawn from the box.
* Second operation: A ball with color 1 is drawn from the box. Gain 1 point.
* Third operation: A ball with color 3 is drawn from the box.

In this case, the total score is 1 point.
The probability that Takahashi's total score is 0 is $\frac{1}{3}$.


### Example 2:
**Sample Input:**
```
3
1 1 3
3 3 3
```
**Sample Output:**
```
0
```

### Example 3:
**Sample Input:**
```
6
1 2 3 3 4 5
3 5 3 5 5 4
```
**Sample Output:**
```
316110712
```
