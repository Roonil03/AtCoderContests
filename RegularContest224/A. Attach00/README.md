# A - Attach 00
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 300 points

## Description:
Find the minimum value of a positive integer $n$ satisfying the following two conditions.
* $n$ is a multiple of $K$.
* In the decimal representation of $n$, 0 appears two or more times consecutively.

$T$ test cases are given; solve each of them.

## Constraints
* $1 \le T \le 10^5$
* $1 \le K \le 10^9$
* All input values are integers.

## Input
The input is given from Standard Input in the following format, where case$_i$ denotes the $i$-th test case:
```
T
case_1
:
case_T
```

Each test case is given in the following format:
```
K
```

## Output
Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

## Examples:
### Examples 1:
**Sample Input:**
```
3
17
6801
998244353
```
**Sample Output:**
```
1003
34005
16970154001
```
**Explaination:**  
This input contains three test cases.

For the first test case, the minimum value satisfying the conditions is 1003 (= 17 * 59).

For the second test case, the minimum value satisfying the conditions is 34005 (= 6801 * 5). Note that 20403 (= 6801 * 3) does not satisfy the condition.

For the third test case, the minimum value satisfying the conditions is 16970154001 (= 998244353 * 17). As this shows, the answer may not fit in a 32-bit integer.