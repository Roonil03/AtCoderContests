# E - Roads and Gates
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 450 points

## Description:

The country of AtCoder has $N$ cities and $M$ roads. The $i$-th road ($1 \le i \le M$) connects cities $u_i$ and $v_i$ bidirectionally and allows travel between them in $T_i$ minutes.

Additionally, each city has a warp gate installed. You can travel from city $i$ ($1 \le i \le N$) to city $j$ ($1 \le j \le N$) using these warp gates in $X_i + X_j + Y$ minutes. There are no other ways to travel between cities.

For each $k = 2, 3, \dots, N$, find the minimum time required to travel from city 1 to city $k$.


## Constraints
* $2 \le N \le 2 \times 10^5$
* $0 \le M \le 2 \times 10^5$
* $1 \le u_i < v_i \le N$
* $1 \le T_i \le 10^9$
* $1 \le X_i \le 10^9$
* $1 \le Y \le 10^9$
* All input values are integers.

## Input Format
```text
N M Y
u1 v1 T1
u2 v2 T2
:
uM vM TM
X1 X2 ... XN

```

## Output Format

Output the minimum travel times for $k = 2, 3, \dots, N$ in this order, separated by spaces.

## Examples:
### Example 1:
**Sample Input:**
```
7 7 3
1 2 1
1 3 6
2 3 4
3 5 8
3 7 4
4 5 2
4 7 9
3 1 4 1 5 9 2
```
**Sample Output:**
```
1 5 6 8 14 7
```
**Explaination:**  
You can travel from city 1 to city 7 in 7 minutes as follows:
* Use the first road to travel from city 1 to city 2 in 1 minute.
* Use the warp gate to travel from city 2 to city 7 in $X_2 + X_7 + Y$ (or $1 + 2 + 3 = 6$) minutes.

It is impossible to travel from city 1 to city 7 in 6 minutes or less, so the answer for $k = 7$ is 7.
### Example 2:
**Sample Input:**
```
2 0 1000000000
1000000000 1000000000
```
**Sample Output:**
```
3000000000
```
**Explaination:**  
Note that the answer may be $2^{31}$ or greater.

### Example 3:
**Sample Input:**
```
12 20 873
2 7 940
6 9 444
6 11 809
7 8 786
9 10 468
7 10 234
6 10 660
4 12 939
8 10 896
1 11 953
8 10 818
4 8 967
3 9 724
6 7 929
3 4 948
1 3 999
10 11 724
7 10 338
1 8 967
1 12 733
581 978 950 629 583 729 554 712 438 930 774 279
```
**Sample Output:**
```
2432 999 1672 2037 1762 1753 967 1723 1677 953 733
```
