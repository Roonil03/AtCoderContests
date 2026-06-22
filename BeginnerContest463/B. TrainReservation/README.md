# B - Train Reservation
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 200 points

## Description:
Takahashi is trying to reserve a seat on a train. There are $N$ trains he is considering as candidates, numbered $1, 2, \dots, N$. Each train has seats in five columns: A, B, C, D, and E.

The current seat availability for each train is given as a string $S_i$ of length 5, where:
* The 1st character corresponds to column A.
* The 2nd character corresponds to column B.
* The 3rd character corresponds to column C.
* The 4th character corresponds to column D.
* The 5th character corresponds to column E.

If the character is 'o', the seat is vacant. If the character is 'x', the seat is occupied.

Takahashi wants to reserve a seat in column $X$ (where $X \in \{A, B, C, D, E\}$). Determine whether there is a vacant seat in column $X$ on at least one train.

## Constraints
* $1 \le N \le 100$
* $X \in \{A, B, C, D, E\}$
* $S_i$ is a string of length 5 consisting of 'o' and 'x'.

## Input Format
```text
N X
S1
S2
:
SN

```

## Output Format

If there is at least one vacant seat in column $X$ on any train, output `Yes`; otherwise, output `No`.

## Examples:
### Example 1:
**Sample Input:**
```
3 A
xoxox
xxooo
oxxxx
```
**Sample Output:**
```
Yes
```
**Explaination:**  
Train 
3 has a vacant seat in column A. Thus, output Yes.

### Example 2:
**Sample Input:**
```
5 C
xoxoo
oxxoo
oxxxo
xoxxx
oxxoo
```
**Sample Output:**
```
No
```
**Explaination:**  
No train has a vacant seat in column C. Thus, output No.

