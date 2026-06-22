# D - Maximize the Gap
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 400 points

## Description:
There are $N$ cloths on a number line. The $i$-th cloth ($1 \le i \le N$) covers the interval $[L_i, R_i]$ on the line. A point on the line may be covered by two or more cloths, or not covered by any cloth.

Two cloths are said to **overlap** if some point on the line is covered by both of those cloths.

For two cloths that do not overlap, define their **distance** as:
* The minimum value of $|p - q|$ over all points $p$ covered by one cloth and all points $q$ covered by the other cloth.

For $K$ cloths no two of which overlap, define their **score** as the minimum distance among all pairs of those cloths. Find the maximum possible score when choosing $K$ cloths from the $N$ cloths so that no two of the chosen cloths overlap.

If it is impossible to choose $K$ such cloths, output `-1`.

## Constraints
* $2 \le K \le N \le 2 \times 10^5$
* $0 \le L_i < R_i \le 10^9$ ($1 \le i \le N$)
* All input values are integers.

## Input Format
The input is given from Standard Input in the following format:

```text
N K
L1 R1
L2 R2
:
LN RN

```

## Output Format

Output the answer (maximum possible score).

## Examples:
### Example 1:
**Sample Input:**
```
6 3
1 12
2 7
5 9
9 13
10 18
15 20
```
**Sample Output:**
```
2
```
**Explaination:**  
Choosing the second, fourth, and sixth cloths, no two of these overlap. The distance between the second and fourth cloths is 
2, the distance between the second and sixth cloths is 
8, and the distance between the fourth and sixth cloths is 
2, so the score of this choice is 
2.

It is impossible to choose three cloths with a score of 
3 or more, so output 2.


### Examples 2:
**Sample Input:**
```
2 2
1 5
5 9
```
**Sample Output:**
```
-1
```
**Explaination:**  
The given two cloths overlap, so it is impossible to choose two cloths so that no two overlap. Thus, output -1.

Note that the first and second cloths overlap only at the single point 
5.

### Example 3:
**Sample Input:**
```
20 5
169 748
329 586
529 972
432 520
408 587
138 250
114 656
299 632
755 984
404 772
155 506
832 854
353 465
374 387
384 567
555 631
428 951
104 705
405 530
102 258
```
**Sample Output:**
```
35
```
