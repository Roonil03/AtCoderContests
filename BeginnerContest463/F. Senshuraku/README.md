# F - Senshuraku
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:

A tournament is being held with $2N$ players. Each player will play exactly one match. In the remaining $N$ matches, the $i$-th ($1 \le i \le N$) match is played between the $(2i - 1)$-th and $2i$-th players.

In each match, one of the two competing players wins and the other loses. The outcome is determined independently for each match, and each player wins with a probability of $\frac{1}{2}$.

Before the last $N$ matches begin, the $i$-th ($1 \le i \le 2N$) player has already won $A_i$ times. After all matches are over, the champion is chosen from among the players with the most total wins, selected uniformly at random and independently of the previous match results.

For each of the $2N$ players, find the probability of that player becoming the champion, expressed modulo 998244353.

### Definition of probability modulo 998244353
The sought probability is a rational number $\frac{P}{Q}$ where $Q \not\equiv 0 \pmod{998244353}$. The answer is the unique integer $R$ such that $R \times Q \equiv P \pmod{998244353}$ and $0 \le R < 998244353$.

## Constraints
* $1 \le N \le 2 \times 10^5$
* $0 \le A_i < 2N$ ($1 \le i \le 2N$)
* All input values are integers.

## Input Format
```text
N
A1 A2
A3 A4
:
A2N-1 A2N

```

## Output Format

Output the probability of the 1st player becoming the champion, the 2nd player, ..., the $2N$-th player, in this order, separated by spaces on a single line.

## Examples:
### Example 1:
**Sample Input:**
```
4
1 2
3 4
2 3
1 4
```
**Sample Output:**
```
0 0 259959467 883862188 0 967049217 0 883862188
```
**Explaination:**  
For example, the third player becomes the champion in the following cases:

* If the third player wins in the second match, the fifth player wins in the third match, and the seventh player wins in the fourth match, the third player becomes the champion with probability $\frac{1}{3}$.
* If the third player wins in the second match, the sixth player wins in the third match, and the seventh player wins in the fourth match, the third player becomes the champion with probability $\frac{1}{4}$.

Thus, the probability of the third player becoming the champion is $\frac{1}{8} \times \frac{1}{3} + \frac{1}{8} \times \frac{1}{4} = \frac{7}{96}$. We have $259959467 \times 96 \equiv 7 \pmod{998244353}$, so the probability of the third player becoming the champion in modulo-998244353 expression is $259959467$.

The probability of each player becoming the champion is $0, 0, \frac{7}{96}, \frac{43}{96}, 0, \frac{3}{96}, 0, \frac{43}{96}$. Thus, output `0 0 259959467 883862188 0 967049217 0 883862188`.
### Example 2:
**Sample Input:**
```
6
0 0
0 0
0 0
0 0
0 0
0 0
```
**Sample Output:**
```
582309206 582309206 582309206 582309206 582309206 582309206 582309206 582309206 582309206 582309206 582309206 582309206
```
**Explaination:**  
It is possible that no one has won yet. By symmetry, each player becomes the champion with probability $\frac{1}{12}$.

### Example 3:
**Sample Input:**
```
10
18 17
16 18
18 16
16 16
17 17
16 16
17 16
17 18
16 16
17 18
```
**Sample Output:**
```
357877533 151989635 0 357877533 357877533 0 0 0 575116994 575116994 0 0 597386855 0 151989635 357877533 0 0 151989635 357877533
```
