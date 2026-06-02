# F - -1, +1
### Time Limit: 2 sec / Memory Limit: 1024 MiB 
## Score : 525 points
## Description:
You are given a sequence of non-negative integers A = (A<sub>1</sub>​,A<sub>2</sub>​,…,A<sub>N</sub>​) of length N.

You can perform the following operation on A zero or more times:
- Choose an integer i with 1 ≤ i ≤ `N−1`, decrease A<sub>i</sub>​ by 1, and increase A<sub>i+1</sub>​ by 1.

Find the minimum number of operations required to make A strictly increasing.

It can be proved that the answer is less than 2<sup>63</sup>.

You are given T test cases; solve each.

## Constraints
- 1 ≤ T ≤ 3 × 10<sup>5</sup>
- 1 ≤ N ≤ 2 × 10<sup>5</sup>
- 0 ≤ A<sub>i</sub> ​≤ 10<sup>9</sup>
- The sum of N across all test cases is at most 6 × 10<sup>5</sup>.
- All input values are integers.

## Input Format:
The input is given from Standard Input in the following format:
```
T
case1​
case2​
⋮
caseT​
```
The i-th (1≤i≤T) test case casei​ is given in the following format:
```
N
A1​ A2​ … AN​
```

## Output Format:
Output the answers for the test cases in order, separated by newlines.

## Examples:
### Example 1:
**Sample Input:**
```
4
3
0 1 0
4
4 6 3 5
7
1 2 3 4 5 6 7
10
11 9 1 3 17 19 10 19 17 3
```
**Sample Output:**
```
3
5
0
78
```
**Explaination**  
Consider the first test case.

By performing the following operations, A can be made strictly increasing in three operations:
- Choose i=1. A becomes `(−1,2,0)`.
- Choose i=2. A becomes `(−1,1,1)`.
- Choose i=2. A becomes `(−1,0,2)`.

It is impossible to make A strictly increasing in fewer than three operations, so output 3.