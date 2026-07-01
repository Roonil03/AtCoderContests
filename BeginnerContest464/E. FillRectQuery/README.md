# E - Fill-Rect Query
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 450 points

## Description:

There is an $H \times W$ grid. Initially, every cell has `A` written on it. The cell at the $i$-th row from the top and $j$-th column from the left is denoted by $(i, j)$.

We will perform $Q$ operations in order.
In the $i$-th operation, overwrite all cells in the rectangle with upper-left cell $(1, 1)$ and lower-right cell $(R_i, C_i)$ with the uppercase English letter $X_i$.

Output the grid after all operations have been performed.

## Constraints
* $1 \le H, W$
* $H \times W \le 10^6$
* $1 \le Q \le 2 \times 10^5$
* $1 \le R_i \le H$
* $1 \le C_i \le W$
* $X_i$ is an uppercase English letter.
* All input numbers are integers.

## Input

The input is given from Standard Input in the following format:
```
H W Q
R_1 C_1 X_1
R_2 C_2 X_2
:
R_Q C_Q X_Q
```

## Output

Print $H$ lines. The $i$-th line should contain a string of length $W$, whose $j$-th character is the uppercase English letter written on $(i, j)$ in the grid after the operations.

## Examples:
### Example 1:
**Sample Input:**
```
2 3 3
2 2 B
1 3 C
2 1 D
```
**Sample Output:**
```
DCC
DBA
```
**Explaination:**  
The operations proceed as shown in the figure.  
<img src="https://img.atcoder.jp/abc464/4691e1b9f6070a3150b57d5fac58aee4.png"><br>

### Example 2:
**Sample Input:**
```
1 7 7
1 7 E
1 6 C
1 5 N
1 4 A
1 3 V
1 2 D
1 1 A
```
**Sample Output:**
```
ADVANCE
```

### Example 3:
**Sample Input:**
```
10 10 15
8 9 B
6 7 C
5 8 D
10 6 E
8 5 F
3 10 G
7 3 H
4 6 I
3 1 J
10 2 K
3 6 L
3 3 M
2 5 N
9 1 O
1 4 P
```
**Sample Output:**
```
PPPPNLGGGG
ONNNNLGGGG
OMMLLLGGGG
OKIIIIDDBA
OKHFFEDDBA
OKHFFECBBA
OKHFFEBBBA
OKFFFEBBBA
OKEEEEAAAA
KKEEEEAAAA
```
