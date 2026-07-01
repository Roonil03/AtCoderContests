# F - Random Vault Heist
### Time Limit: 3 sec / Memory Limit: 1024 MiB

## Score : 550 points

## Description:
Kowasugi Bank has $N$ safes. Safe $i$ contains $A_i$ yen.

One day, a robber entered the bank. The robber repeats the following operation until the total amount stolen reaches at least $X$ yen:

* Choose one safe uniformly at random from the safes not yet opened, open it, and steal all the money inside.

Find the expected value, modulo 998244353, of the total amount stolen by the robber.

### Definition of expected value modulo 998244353
It can be proved that the expected value sought is always a rational number. Moreover, under the constraints of this problem, it can also be proved that when this value is expressed as an irreducible fraction $\frac{P}{Q}$, it satisfies $Q \not\equiv 0 \pmod{998244353}$. Therefore, there exists a unique integer $R$ satisfying $R \times Q \equiv P \pmod{998244353}, 0 \le R < 998244353$. Find this $R$.

## Constraints
* $1 \le N \le 40$
* $1 \le A_i \le 10^{16}$
* $1 \le X \le \sum_{i=1}^{N} A_i$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
N X
A_1 A_2 ... A_N
```

## Output
Output the answer.

## Examples:
### Example 1:
**Sample Input:**
```
2 5
3 10
```
**Sample Output:**
```
499122188
```
**Explaination:**  
There are two choices for the first safe to open.

* If safe 1 is opened first, the robber also opens safe 2, so the total amount stolen is 13 yen.
* If safe 2 is opened first, the total already reaches at least $X$ yen at that point, so the total amount stolen is 10 yen.

Thus, the expected value is $\frac{13+10}{2} = \frac{23}{2}$.

### Example 2:
**Sample Input:**
```
3 2
1 1 1
```
**Sample Output:**
```
2
```
**Explaination:**  
Regardless of the order in which they are opened, the total amount stolen when two safes have been opened is 2 yen. Thus, the expected value is 2.

### Example 3:
**Sample Input:**
```
11 60
2 3 5 7 11 13 17 19 23 29 31
```
**Sample Output:**
```
525950964
```
