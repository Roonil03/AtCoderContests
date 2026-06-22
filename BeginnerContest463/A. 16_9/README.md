# A - 16:9
### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score: 100 points

## Description:
Given an image with a width of $X$ pixels and a height of $Y$ pixels, determine whether the ratio of the width to the height is 16:9. That is, check if $X : Y = 16 : 9$.

## Constraints
* $1 \le X \le 1000$
* $1 \le Y \le 1000$
* All input values are integers.

## Input Format
The input is provided from Standard Input in the following format:

```text
X Y

```

## Output Format

If the ratio of the width to the height is 16:9, output `Yes`; otherwise, output `No`.

## Examples:
### Example 1:
**Sample Input:**
```
800 450
```
**Sample Output:**
```
Yes
```
**Explaination:**  
For an image with a width of 
800 pixels and a height of 
450 pixels, the ratio of the width to the height is 
16 to 
9.

### Example 2:
**Sample Input:**
```
234 108
```
**Sample Output:**
```
No
```
**Explaination:**  
For an image with a width of 
234 pixels and a height of 
108 pixels, the ratio of the width to the height is not 
16 to 
9.

### Example 3:
**Sample Input:**
```
108 192
```
**Sample Output:**
```
No
```
**Explaination:**  
For an image with a width of 
108 pixels and a height of 
192 pixels, the ratio of the width to the height is not 
16 to 
9.