# A - Compromise
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 100 points

## Description:
There are $N$ choices.

You will choose one of these choices. If you choose the $i$-th choice, your happiness will be $X_i$.

If your happiness will be negative no matter which choice you choose, output Yes; otherwise, output No.

## Constraints
* $2 \le N \le 10$
* $-100 \le X_i \le 100$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
N
X_1  X_2  ...  X_N
```

## Output
Output Yes or No according to the instructions in the problem statement.

## Examples:
### Example 1:
**Sample Input:**
```
4
2 0 -1 2
```
**Sample Output:**
```
No
```
**Explaination:**  
If you choose choice 1, 2, or 4, the happiness will not be negative.

### Example 2:
**Sample Input:**
```
3
-5 -2 -1
```
**Sample Output:**
```
Yes
```

### Example 3:
**Sample Input:**
```
4
0 -2 0 -1
```
**Sample Output:**
```
No
```
