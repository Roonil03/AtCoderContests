# C - Tallest at the Moment
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 300 points

## Description:
There are $N$ people named Takahashi in a conference room. The $i$-th Takahashi ($1 \le i \le N$) has a height of $H_i$ and will leave the room $L_i$ minutes from now. Once a Takahashi leaves the room, he never returns.

You are given $Q$ queries. For the $i$-th query, you are given an integer $T_i$. Find the maximum height among all Takahashi currently in the room at time $T_i + 0.5$ minutes from now. 

**Note:** It is guaranteed that at least one Takahashi will be in the room at time $T_i + 0.5$.

## Constraints
* $1 \le N \le 3 \times 10^5$
* $1 \le H_i \le 10^9$
* $1 \le L_1 \le L_2 \le \dots \le L_N \le 10^9$
* $1 \le Q \le 3 \times 10^5$
* $0 \le T_i < L_N$

## Input Format
The input is given from Standard Input in the following format:

```text
N
H1 L1
H2 L2
:
HN LN
Q
T1 T2 ... TQ
```

## Output Format

Output $Q$ lines. The $i$-th line should contain the answer to the $i$-th query.

## Examples:
### Example 1:
**Sample Input:**
```
4
31 4
26 5
3 5
15 9
4
3 4 5 6
```
**Sample Output:**
```
31
26
15
15
```
**Explaination:**  
* $3 + \frac{1}{2}$ minutes from now, all Takahashi currently in the room are still there. Thus, the answer to the first query is $31$, the maximum of $\{31, 26, 3, 15\}$.
* $5 + \frac{1}{2}$ minutes from now, only the fourth Takahashi is in the room. Thus, the answer to the third query is $15$, the maximum of $\{15\}$.

### Example 2:
**Sample Input:**
```
10
587 138
772 155
755 404
519 408
529 432
169 586
114 632
249 656
329 972
299 984
14
443 801 824 276 399 314 300 510 311 580 498 930 359 5
```
**Sample Output:**
```
329
329
329
755
755
755
755
329
755
329
329
329
755
772
```
