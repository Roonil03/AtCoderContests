# D - Adjacent Distinct String
###  Time Limit: 2 sec / Memory Limit: 1024 MiB 
## Score: 400 points

## Description:
You are given a string S consisting of lowercase English letters.

Determine whether it is possible to rearrange the characters of S so that no two adjacent characters are the same, and if so, find one such rearrangement.

You are given T test cases; solve each.

## Constraints
- 1 ≤ T ≤ 3 × 10<sup>5</sup>
- S is a string of length between 1 and 10<sup>6</sup>, inclusive, consisting of lowercase English letters.
- The total length of S across all test cases is at most 10<sup>6</sup>.

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
S
```

## Output Format:
Output the answers for the test cases in order, separated by newlines.

For each test case, if it is impossible to rearrange S so that no two adjacent characters are the same, output No.

If it is possible, let S′ be such a rearrangement and output in the following format:
```
Yes
S′
```
If there are multiple valid rearrangements of S, any of them will be accepted.

## Examples:
### Example 1:
**Sample Input**
```
3
aiiw
doodoo
aabbababcacababaaba
```
**Sample Output:**
```
Yes
iwai
No
Yes
ababacabababacababa
```
**Explaination:**  
Consider the first test case.

`iwai` is a rearrangement of `aiiw` in which no two adjacent characters are the same. Thus, outputting `iwai` is correct.

Other correct outputs include `wiai` and `iawi`.
