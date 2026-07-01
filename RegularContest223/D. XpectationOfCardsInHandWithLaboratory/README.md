# D - Xpectation of Cards in Hand with Laboratory

### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 600 points

## Description:
There are $A$ "draw" cards and $B$ normal cards. Among the $(A + B)!$ permutations of these $A + B$ cards, one is chosen uniformly at random, and the cards are stacked top to bottom in that order to form a deck. Then, $K$ cards are drawn from the top of the deck and placed in your hand. As long as your hand contains at least one draw card, repeat the following operation:

* Discard one draw card from your hand. The discarded card is removed from your hand and does not return to the deck.
* Let $c$ be the number of cards remaining in the deck. Add $\min(c, 2)$ cards from the top of the deck to your hand.

Find the expected number, modulo 998244353, of cards in your final hand.

Solve $T$ test cases per input.

### Definition of modulo 998244353
Under the constraints of this problem, it can be proved that the answer is a rational number, and that when it is expressed as an irreducible fraction $\frac{P}{Q}$, it satisfies $Q \not\equiv 0 \pmod{998244353}$. Thus, the integer $R$ satisfying $R \times Q \equiv P \pmod{998244353}, 0 \le R < 998244353$ is uniquely determined. Output this $R$.

## Constraints

* $1 \le T \le 10^5$
* $1 \le A, B$
* $1 \le K \le A + B \le 10^7$
* The sum of $A + B$ over all test cases is at most $10^7$.
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

Each test case $\text{case}_t$ is given in the following format:
```
A B K
```

## Output
Output the answers over a total of $T$ lines. The $t$-th line should contain the answer for the $t$-th test case.

## Examples:
### Example 1:
**Sample Input:**
```
4
2 2 3
1 2 1
10 20 4
20 10 4
```
**Sample Output:**
```
2
332748119
944679050
774829082
```
**Explaination:**  
For the first test case, the initial hand always contains at least 1 draw card, and the deck has 1 card remaining. After performing the operation once, the hand contains 1 draw card and 2 normal cards. After performing the operation once more, the hand contains 0 draw cards and 2 normal cards.  
For the second test case, the final hand size is 2 if the first drawn card is a draw card, and 1 if it is a normal card. The expected value is $\frac{1}{3} \times 2 + \frac{2}{3} \times 1 = \frac{4}{3}$.
