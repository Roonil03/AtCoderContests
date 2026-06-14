# B - Gift
### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 200 points

## Description:
$N$ people, numbered 1 through $N$, exchanged gifts with each other.
Person $i$ sent gifts to $K_i$ people: persons $A_{i,1}, A_{i,2}, \dots, A_{i,K_i}$.
For each $i = 1, 2, \dots, N$, find all people who sent a gift to person $i$.

## Constraints
* $2 \le N \le 100$
* $1 \le K_i \le N - 1$
* $1 \le A_{i,1} < A_{i,2} < \dots < A_{i,K_i} \le N$
* $A_{i,j} \neq i$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:

```
N
K_1  A_{1,1}  A_{1,2}  ...  A_{1,K_1}
K_2  A_{2,1}  A_{2,2}  ...  A_{2,K_2}
:
K_N  A_{N,1}  A_{N,2}  ...  A_{N,K_N}

```

## Output

Output $N$ lines.

For the $i$-th line, let $B_1, B_2, \dots, B_X$ be the numbers of the people who sent a gift to person $i$, listed in ascending order (where $X$ is the count of people who sent a gift to person $i$), and output in the following format:

```
X  B_1  B_2  ...  B_X

```

## Examples:
### Example 1:
**Sample Input:**
```
4
1 2
1 3
1 2
3 1 2 3
```
**Sample Output:**
```
1 4
3 1 3 4
2 2 4
0
```
**Explaination:**  
Person 
1 sent a gift to person 
2, person 
2 sent a gift to person 
3, person 
3 sent a gift to person 
2, and person 
4 sent gifts to persons 
1,2,3.

Person 
1 received a gift from person 
4. Thus, output 1 4 on the first line.

Person 
2 received gifts from persons 
1,3,4. Thus, output 3 1 3 4 on the second line.

Person 
3 received gifts from persons 
2,4. Thus, output 2 2 4 on the third line.

Person 
4 did not receive any gifts. Thus, output 0 on the fourth line.

### Example 2:
**Sample Input:**
```
4
3 2 3 4
2 1 4
2 1 2
2 2 3
```
**Sample Output:**
```
2 2 3
3 1 3 4
2 1 4
2 1 2
```
### Example 3:
**Sample Input:**
```
7
1 3
4 3 4 6 7
1 7
3 2 6 7
2 3 7
1 4
1 5
```
**Sample Output:**
```
0
1 4
3 1 2 5
2 2 6
1 7
2 2 4
4 2 3 4 5
```