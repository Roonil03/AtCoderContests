# B - 459
### Time Limit: 2 sec / Memory Limit: 1024 MiB 

## Score : 200 points

## Description:
You are given N strings S<sub>1</sub>,S<sub>2​</sub>,…,S<sub>N</sub>​ consisting of lowercase English letters.

Define N digits C<sub>1</sub>​,C<sub>2</sub>​,…,C<sub>N</sub>​ as follows:
- If the first character of S<sub>i</sub>​ is one of a, b, c, then C<sub>i</sub>​= 2
- If the first character of S<sub>i</sub>​ is one of d, e, f, then C<sub>i</sub>​= 3
- If the first character of S<sub>i</sub>​ is one of g, h, i, then C<sub>i</sub>​= 4
- If the first character of Si<sub>i</sub> is one of j, k, l, then C<sub>i</sub>​= 5
- If the first character of S<sub>i</sub>​ is one of m, n, o, then Ci<sub>i</sub>= 6
- If the first character of S<sub>i</sub>​ is one of p, q, r, s, then C<sub>i</sub>= 7
- If the first character of Si<sub>i</sub> is one of t, u, v, then Ci<sub>i</sub>= 8
- If the first character of S<sub>i</sub> is one of w, x, y, z, then C<sub>i</sub>​= 9

Output the string obtained by concatenating C<sub>1</sub>​,C<sub>2</sub>​,…,C<sub>N</sub>​ in this order.

## Constraints:
- 1 ≤ N ≤ 10
- N is an integer.
- S<sub>i</sub>​ is a string of length between 1 and 10, inclusive, consisting of lowercase English letters.

## Input Format:
The input is given from Standard Input in the following format:
```
N
S1​ S2​ … SN​
```
## Output Format:

Output the string obtained by concatenating C<sub>1</sub>​,C<sub>2</sub>​,…,C<sub>N</sub>​ in this order.

## Examples:
### Example 1:
**Sample Input:**
```
2
algorithm heuristic
```
**Sample Output:**
```
24
```
**Explaination:**  

- The first character of S<sub>1</sub>​= algorithm is a, so C<sub>1</sub>​= 2.
- The first character of S<sub>2</sub>​= heuristic is h, so C<sub>2</sub>​= 4.

Thus, output 24, which is their concatenation.

### Example 2:
**Sample Input:**
```
3
i love you
```
**Sample Output:**
```
459
```