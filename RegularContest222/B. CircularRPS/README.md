# B - Circular RPS
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 500 points

## Description:
A rock-paper-scissors tournament was held with $a + b + c$ participants. Here, $a, b, c$ are non-negative integers with $3 \le a + b + c$.

In the tournament, all participants first stand in a circle. Then, each participant plays "Rock," "Scissors," or "Paper."

For each participant, if the hand they played beats both the hand of the participant to their left and the hand of the participant to their right, that participant becomes a winner. There is not necessarily exactly one winner; there may be zero, or two or more winners.

More formally, a participant becomes a winner if one of the following holds:
* The participant played "Rock," and both the left neighbor and the right neighbor played "Scissors."
* The participant played "Scissors," and both the left neighbor and the right neighbor played "Paper."
* The participant played "Paper," and both the left neighbor and the right neighbor played "Rock."

The following is known about this tournament:
* $a$ participants played "Rock."
* $b$ participants played "Scissors."
* $c$ participants played "Paper."

Under this condition, find the maximum possible number of winners in the tournament.

$T$ test cases are given; solve each of them.

## Constraints
* $1 \le T \le 5 \times 10^5$
* $0 \le a, b, c \le 10^9$
* $3 \le a + b + c$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:
```
T
case_1
case_2
:
case_T

```

Each test case is given in the following format:

```
a b c

```

## Output

Output one line per test case.
For each test case, output the maximum possible number of winners in the tournament.

## Examples:
### Example 1:
**Sample Input:**
```
6
3 1 2
2 2 2
123 456 789
10 0 0
10 0 100
100 0 10
```
**Sample Output:**
```
2
1
578
0
9
10
```
**Explaination:**  
Let us explain the first test case. Consider the case where the hands played by the six participants are represented as in the following figure. In the figure, a participant who played "Rock" is denoted by A, a participant who played "Scissors" is denoted by B, and a participant who played "Paper" is denoted by C.

<img src="https://img.atcoder.jp/arc222/eb5e0d3d8c8b4d04cef8439b557fd0db.png"><br>

In this figure, there are three participants who played "Rock," one participant who played "Scissors," and two participants who played "Paper," which matches the input. In this case, the winners of the tournament are the two participants who played "Paper."