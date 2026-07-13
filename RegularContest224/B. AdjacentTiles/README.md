# B - Adjacent Tiles
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 400 points

## Description:
Let us place $N$ square tiles of the same size on a plane so that they do not overlap.
Then, what is the maximum possible number of pairs of different tiles that share one full side?

Here, a pair of different tiles $(a, b)$ is said to share one full side if and only if some side of $a$ and some side of $b$ coincide completely.
$T$ test cases are given; solve each of them.

## Constraints
* $1 \le T \le 2 \times 10^5$
* $1 \le N \le 10^{18}$
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
N
```

## Output
Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
6
1
2
3
4
100000000000000000
1000000000000000000
```
**Sample Output:**
```
0
1
2
4
199999999367544467
1999999998000000000
```
**Explaination:**  
This input contains six test cases.

The figure below shows an example of an optimal arrangement of tiles for N = 1, 2, 3, 4.
* For the first test case, N = 1.
    * There is no pair of different tiles sharing one full side.
* For the second test case, N = 2.
    * The pair of tiles (a, b) shares one full side.
* For the third test case, N = 3.
    * The pairs of tiles (a, b), (b, c) share one full side.
* For the fourth test case, N = 4.
    * The pairs of tiles (a, b), (a, c), (b, d), (c, d) share one full side.

<img src="https://img.atcoder.jp/arc224/8aea669e2ca752ca51efd2115ba06edc.png"><br>