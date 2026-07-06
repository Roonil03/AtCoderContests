# B - Parking 2
### Time Limit: 2 sec / Memory Limit: 1024 MiB
## Score : 200 points

## Description:
You are given a parking lot with a tiered fee structure:
* During the period from exactly $L$ o'clock to exactly $R$ o'clock, a fee of $X$ is charged for each hour parked.
* Outside of this specific period, a fee of $Y$ is charged for each hour parked.

Given that a car is parked from exactly $A$ o'clock to exactly $B$ o'clock (without crossing midnight), calculate the total parking fee.

## Input Format
The input is provided from Standard Input in the following format:
```
X Y L R A B
```

## Constraints
* $1 \leq X, Y \leq 1000$
* $1 \leq L < R \leq 23$
* $1 \leq A < B \leq 23$
* All input values are integers.

## Examples
**Sample Input:**
```
700 300 9 17 7 21
```
**Sample Output:**
```
7400
```
**Explanation:**  
For parking from 7 to 21:
* 7 to 9 (2 hours at rate $Y=300$): $2 \times 300 = 600$
* 9 to 17 (8 hours at rate $X=700$): $8 \times 700 = 5600$
* 17 to 21 (4 hours at rate $Y=300$): $4 \times 300 = 1200$
* Total: $600 + 5600 + 1200 = 7400$

### Example 2:
**Sample Input:**
```
600 500 9 17 17 20
```
**Sample Output:**
```
1500
```
**Explanation:**  
For parking from 17 to 20:
* 17 to 20 (3 hours at rate $Y=500$): $3 \times 500 = 1500$  

### Example 3:
**Sample Input:**
```
900 200 12 14 11 13
```
**Sample Output:**
```
1100
```