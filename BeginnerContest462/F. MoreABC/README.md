# F - More ABC
### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 500 points

## Description:
You are given a string $S$ consisting of uppercase English letters.  
Takahashi's goal is to **increase** the number of occurrences of `ABC` as a substring of $S$ by exactly $K$, by replacing some characters of $S$.

Determine whether this is possible, and if so, find the minimum number of characters Takahashi needs to replace to achieve his goal.

$T$ test cases are given; solve each one.

### Definitions
* **What does "replacing" mean?**
  Replacing one character of $S$ means choosing an integer $i$ satisfying $1 \le i \le |S|$ and replacing the $i$-th character of $S$ with any **one** uppercase English letter.
  Here, $|S|$ denotes the length of $S$.

* **What is a substring?**
  A substring of $S$ is a string obtained by removing zero or more characters from the beginning and end of $S$.
  Two substrings are counted as distinct if they are taken from different positions in $S$, even if they are equal as strings.

## Constraints
* $1 \le T \le 10^5$
* $S$ is a string of length between 3 and $3 \times 10^5$, inclusive, consisting of uppercase English letters.
* $1 \le K \le 10$
* In each input, the total length of $S$ over all test cases is at most $3 \times 10^5$.
* $T$ and $K$ are integers.

## Input
The input is given from Standard Input in the following format:

```
T
case_1
case_2
:
case_T
```

`case_i` represents the $i$-th test case.
Each test case is given in the following format:

```
S
K
```

## Output

Output $T$ lines.  
The $i$-th line ($1 \le i \le T$) should contain the answer for the $i$-th test case.  
For each test case, if it is impossible for Takahashi to achieve his goal, output $-1$; otherwise, output the minimum number of characters that need to be replaced to achieve his goal.

## Examples:
### Example 1:
**Sample Input:**
```
5
ATCABC
1
ABABC
1
XABCYZ
1
ZZZZZ
1
ABCBABCAEFCABAABC
2
```
**Sample Output:**
```
1
-1
6
3
3
```
**Explaination:**  
* In the first test case, the given string $S = \text{ATCABC}$ contains `ABC` as a substring once.  
Replacing the second character of $S$ with `B` gives $S = \text{ABCABC}$, which contains `ABC` as a substring twice.  
Thus, replacing one character increases the number of occurrences of `ABC` as a substring by 1, achieving the goal. Therefore, output 1 on the first line.
* In the second test case, the given string $S = \text{ABABC}$ contains `ABC` as a substring once; no matter how the characters of $S$ are replaced, it is impossible to make $S$ contain `ABC` as a substring twice.  
Therefore, output $-1$ on the second line.
* In the third test case, the given string $S = \text{XABCYZ}$ contains `ABC` as a substring once.  
To make $S$ contain `ABC` as a substring twice, all characters of $S$ must be replaced, giving $S = \text{ABCABC}$.  
Therefore, output 6 on the third line.

