# D - Celester
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 400 points

## Description:
The weather for the upcoming $N$ days is given as a string $S$.
If the $i$-th character of $S$ is `S`, then the weather on day $i$ is sunny; if it is `R`, then the weather on day $i$ is rainy.
Also, your current happiness is 0.

You can perform the following operation any number of times, possibly zero:

* Choose an integer $i$ with $1 \le i \le N$.
* If the weather on day $i$ is sunny, change it to rainy; if it is rainy, change it to sunny.
* However, if you change the weather on day $i$, your happiness decreases by $X_i$.

After performing the operations, your happiness increases based on the final weather according to the following condition:

* For each integer $i$ with $1 \le i \le N - 1$, if the weather on day $i$ after modification is rainy and the weather on day $i + 1$ is sunny, your happiness increases by $Y_i$.

Find the maximum value of happiness achievable by performing operations.

$T$ test cases are given; solve each.

## Constraints

* $1 \le T \le 10^4$
* $N$ is an integer between 2 and $2 \times 10^5$, inclusive.
* $S$ is a string of length $N$ consisting of `S` and `R`.
* $X_i$ is an integer between 1 and $10^9$, inclusive.
* $Y_i$ is an integer between 1 and $10^9$, inclusive.
* The sum of $N$ in a single input is at most $2 \times 10^5$.

## Input

The input is given from Standard Input in the following format, where $\text{case}_i$ denotes the $i$-th test case:

```
T
case_1
case_2
:
case_T
```

Each test case is given in the following format:
```
N
S
X_1 X_2 ... X_N
Y_1 Y_2 ... Y_{N-1}

```

## Output

Output $T$ lines. The $i$-th line should contain the answer for the $i$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
5
6
SRRRSR
3 1 4 1 5 9
2 6 5 3 5
6
RSRSRS
10 10 10 10 10 10
1 1 1 1 1
2
RR
4 3
2
10
RSSRSSRSSR
75 49 79 37 16 9 38 49 69 54
23 100 73 63 66 23 51 65 67
20
SSSRSSSRRRRSSRSSRSSR
343191362 223147518 135066250 426658267 693515093 8023388 383375974 712283203 40447501 19870690 318452142 356265717 283999278 209219229 418603824 39363351 392058270 254796273 110117486 64951139
576697130 385986330 895027325 654885799 784214084 577658764 761714876 583039741 943991250 446493376 701505924 402891440 963636095 919408713 238125227 871191978 843843821 397910552 529447424
```
**Sample Output:**
```
5
3
0
165
5201284760
```
**Explaination:**  
This input contains five test cases.

For the first test case, for example, you can maximize happiness by performing the following operations:
* Change the weather on day 3 from rainy to sunny. Happiness decreases by $X_3 = 4$, and the weather on each day becomes sunny, rainy, sunny, rainy, sunny, rainy.
* As a result of this operation, since day 2 is rainy and day 3 is sunny, happiness increases by $Y_2 = 6$, and since day 4 is rainy and day 5 is sunny, happiness increases by $Y_4 = 3$.
* The total happiness is $(-4) + 6 + 3 = 5$, which is the achievable maximum.

For the second and third test cases, performing no operations may be optimal.

For the fifth test case, note that the answer may not fit in a 32-bit integer type.
