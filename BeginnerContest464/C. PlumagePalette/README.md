# C - Plumage Palette
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 300 points

## Description:
Takahashi observed $N$ birds, numbered $1, 2, \dots, N$, over $M$ days.

Each of the birds that Takahashi observed has one of $N$ colors, numbered $1, 2, \dots, N$, and these birds have an interesting characteristic: their color can change during the observation period.

Bird $i$ had color $A_i$ in observations on or before day $D_i - 1$, and color $B_i$ in observations on or after day $D_i$.
Here, if $D_i = 1$, then the bird's color was $B_i$ from the observation on day $1$, and if $A_i = B_i$, then the bird's color did not change during the observation period.

For each $j = 1, 2, \dots, M$, find the number of different colors of birds on day $j$.

## Constraints

* $1 \le N \le 3 \times 10^5$
* $1 \le M \le 3 \times 10^5$
* $1 \le A_i, B_i \le N$
* $1 \le D_i \le M$
* All input values are integers.

## Input

The input is given from Standard Input in the following format:
```
N M
A_1 D_1 B_1
A_2 D_2 B_2
:
A_N D_N B_N
```

## Output

Output $M$ lines.
The $j$-th line should contain the number of different colors of birds on day $j$.

## Examples:
### Example 1:
**Sample Input:**
```
6 7
1 3 2
2 6 5
5 5 1
3 3 5
4 1 6
6 3 6
```
**Sample Output:**
```
5
5
3
3
4
4
4
```
**Explaination:**  
In this input, six birds are observed over seven days.

* On day 1, the color of each bird was 1, 2, 5, 3, 6, 6. There are 5 different colors in total.
* On day 2, the color of each bird was 1, 2, 5, 3, 6, 6. There are 5 different colors in total.
* On day 3, the color of each bird was 2, 2, 5, 5, 6, 6. There are 3 different colors in total.
* On day 4, the color of each bird was 2, 2, 5, 5, 6, 6. There are 3 different colors in total.
* On day 5, the color of each bird was 2, 2, 1, 5, 6, 6. There are 4 different colors in total.
* On day 6, the color of each bird was 2, 5, 1, 5, 6, 6. There are 4 different colors in total.
* On day 7, the color of each bird was 2, 5, 1, 5, 6, 6. There are 4 different colors in total.
