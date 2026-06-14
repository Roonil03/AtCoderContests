# D - Accomplice
### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 400 points

## Description:
A murder occurred at a certain mansion. There are $N$ suspects, called person 1, person 2, $\dots$, person $N$.

Person $i$ entered the mansion at time $S_i$, left the mansion at time $T_i$, and did not enter or leave at any other times.

The following facts are known about the crime:
* There are exactly two culprits.
* The crime started at some integer time $x$, took $D$ units of time, and was completed at time $x + D$.
* Both culprits were in the mansion at all times from the start to the completion of the crime. (They may have entered the mansion exactly when the crime started, or left exactly when it was completed.)

Assuming that both culprits are among the $N$ suspects, how many combinations of the two culprits and the crime start time are possible? Here, the order of the two culprits does not matter.

## Constraints
* $2 \le N \le 2 \times 10^5$
* $1 \le S_i \le T_i \le 10^6$
* $1 \le D \le 10^6$
* All input values are integers.

## Input
The input is given from Standard Input in the following format:

```text
N  D
S_1  T_1
S_2  T_2
:
S_N  T_N
```

## Output
Output the number of possible combinations of the two culprits and the crime start time.

## Examples:
### Example 1:
**Sample Input:**
```
3 2
9 17
10 12
13 20
```
**Sample Output:**
```
4
```
**Explaination:**  
In this sample, there are three suspects, and the crime took two units of time.

* If persons 1 and 2 are the culprits, they were both in the mansion from time 10 to time 12. If the crime start time is time 10, the crime can be committed in two units of time.
* If persons 1 and 3 are the culprits, they were both in the mansion from time 13 to time 17. If the crime start time is 13, 14, or 15, the crime can be committed in two units of time.
* If persons 2 and 3 are the culprits, they were never in the mansion at the same time, so this pair cannot have committed the crime.

Thus, the possible combinations of the two culprits and the crime start time are (persons 1, 2, time 10), (persons 1, 3, time 13), (persons 1, 3, time 14), (persons 1, 3, time 15), giving four combinations.

### Example 2:
**Sample Input:**
```
3 5
9 17
10 12
13 20
```
**Sample Output:**
```
0
```
**Explaination:**  
The suspects are the same as in Sample Input 1, but this time the crime took five units of time.
No matter which two persons are the culprits, the time they were both in the mansion is shorter than the time required for the crime, so the crime is impossible.
Thus, the number of possible combinations of the two culprits and the crime start time is zero. (In other words, our assumption is wrong, and the real culprit has escaped us.)

### Examples 3:
**Sample Input:**
```
4 1
1 1000000
1 1000000
1 1000000
1 1000000
```
**Sample Output:**
```
5999994
```
**Explaination:**  
Beware of overflow for larger cases.

