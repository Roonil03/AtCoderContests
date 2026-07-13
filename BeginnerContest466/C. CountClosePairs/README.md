# C - Count Close Pairs
### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 300 points

## Description:
This is an interactive problem (in which your program and the judge program communicate via Standard Input and Output).

On a number line, points $1, 2, \dots, N$ are arranged from left to right in that order.

Initially, you are given only the integer $N$.

Then, you can ask the judge the following question at most $2N$ times.
* Choose integers $i$ and $j$ satisfying $1 \le i < j \le N$, and ask whether the distance between points $i$ and $j$ is at most 1.

Output the number of pairs of points whose distance is at most 1, that is, the number of pairs of integers $(i, j)$ satisfying $1 \le i < j \le N$ such that the distance between points $i$ and $j$ is at most 1.

## Constraints
* $2 \le N \le 10^3$
* $N$ is an integer.

## Interaction
First, receive the integer $N$ representing the number of points from Standard Input:
```
N
```
Then, you can repeat the question described in the problem statement to the judge at most $2N$ times.

Output the question to Standard Output in the following format, where $i$ and $j$ must be integers satisfying $1 \le i < j \le N$:
```
? i j
```
As a response to this, one of the following will be given from Standard Input:
```
Yes
```
```
No
```
Here, Yes indicates that the distance between points $i$ and $j$ is at most 1, and No indicates that the distance between points $i$ and $j$ is greater than 1.

Once you have found the answer $X$ to the problem, output your answer in the following format, and then terminate the program immediately:
```
! X
```

## Notes
* Each time you output something, insert a newline at the end and flush Standard Output. Otherwise, the judge result may be **TLE**.
* The judge result is indeterminate if you output something invalid during the interaction, or if the program terminates prematurely.
* Terminate the program immediately after outputting your answer. Otherwise, the judge result is indeterminate.
* The arrangement of the points and the answer are fixed at the start of the interaction between you and the judge, and do not change depending on, for example, the questions you make.

## Sample Interaction
Below is an example of interaction where $N = 3$ and the coordinates of points 1, 2, 3 are 0, 0.7, 1.5, respectively. (The coordinates of points 1, 2, 3 are not given as input.)

| Input | Output | Explanation |
| :--- | :--- | :--- |
| 3 | | $N$ is given. |
| | ? 1 2 | Ask the judge whether the distance between points 1 and 2 is at most 1. |
| Yes | | Obtain the response from the judge that the distance between points 1 and 2 is at most 1. |
| | ? 1 3 | Ask the judge whether the distance between points 1 and 3 is at most 1. |
| No | | Obtain the response from the judge that the distance between points 1 and 3 is not at most 1. |
| | ? 2 3 | Ask the judge whether the distance between points 2 and 3 is at most 1. |
| Yes | | Obtain the response from the judge that the distance between points 2 and 3 is at most 1. |
| | ! 2 | Answer 2 as the number of pairs satisfying the condition. |

The number of questions is 3, which is in particular at most $2N = 6$.  
Since the answered number of pairs is also correct, the program will be judged as correct if it terminates immediately after this.