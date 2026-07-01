# A - Decisive Battle
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 100 points

## Description

The Eastern Army and the Western Army are at war in a certain capital.

Takahashi recorded information about the fighting forces as a string $S$.
$S$ contains only the characters `E` and `W`, and the number of `E`s in $S$ equals the number of soldiers in the Eastern Army, and the number of `W`s equals the number of soldiers in the Western Army.

Given the string $S$ that Takahashi recorded, output `East` if the Eastern Army has more soldiers than the Western Army, or `West` if the Western Army has more soldiers than the Eastern Army.

The length of $S$ is guaranteed to be odd. Thus, it can be proved that exactly one of the two armies strictly outnumbers the other (that is, the two armies cannot have the same number of soldiers).

## Constraints

* $S$ is a string of length between 1 and 99, inclusive, consisting of `E` and `W`.
* The length of $S$ is odd.

## Input
The input is given from Standard Input in the following format:

```
S
```

## Output

Output the answer.

## Examples:
### Example 1:
**Sample Input:**
```
EEWEW
```
**Sample Output:**
```
East
```
**Explaination:**  
S contains three Es and two Ws, so the Eastern Army has three soldiers and the Western Army has two soldiers.  
Since the Eastern Army has more soldiers than the Western Army, output East.

### Example 2:
**Sample Input:**
```
WWWWWWW
```
**Sample Output:**
```
West
```
**Explaination:**  
S contains zero Es and seven Ws, so the Eastern Army has zero soldiers and the Western Army has seven soldiers.  
Since the Western Army has more soldiers than the Eastern Army, output West.
