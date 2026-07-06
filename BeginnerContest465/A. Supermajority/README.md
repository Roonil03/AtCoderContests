# A - Supermajority
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score : 100 points

## Description:
Given two positive integers $A$ and $B$, determine if the condition $A > B \times \frac{2}{3}$ holds true.

* If the condition is satisfied, output `Yes`.
* Otherwise, output `No`.

## Input
The input is provided from Standard Input in the following format:
```
A B
```

## Constraints
* $1 \leq A, B \leq 1000$
* All input values are integers.

## Examples
### Example 1:
**Sample Input:**
```
316 465
```
**Sample Output:**
```
Yes
```
**Explanation:**  
Since $316 > 465 \times \frac{2}{3}$ (which is $316 > 310$), the condition holds.  

### Example 2:
**Sample Input:**
```
101 248
```
**Sample Output:**
```
No
```
**Explanation:**  
Since $101 > 248 \times \frac{2}{3}$ (which is $101 > 165.33$) does not hold.  

### Example 3:
**Sample Input:**
```
666 999
```
**Sample Output:**
```
No
```
**Explanation:**  
Since $666 > 999 \times \frac{2}{3}$ (which is $666 > 666$) does not hold. 
