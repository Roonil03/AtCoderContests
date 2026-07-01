# B - Crop

### Time Limit: 2 sec / Memory Limit: 1024 MiB

## Score :  200 points

## Description:

There is a black-and-white image of height $H$ pixels and width $W$ pixels. The color of the pixel at the $i$-th row from the top and $j$-th column from the left is given as a character $C_{i,j}$, where `.` represents white and `#` represents black.

From the top, bottom, left, and right edges of this image, remove rows and columns where all pixels are white. Specifically, perform the following operations in order:

1. While the topmost row of the image is entirely white, repeat removing the topmost row.
2. While the bottommost row of the image is entirely white, repeat removing the bottommost row.
3. While the leftmost column of the image is entirely white, repeat removing the leftmost column.
4. While the rightmost column of the image is entirely white, repeat removing the rightmost column.

Output the image after processing.

The given image contains at least one black pixel.

## Constraints

* $1 \le H, W \le 50$
* $C_{i,j}$ is `.` or `#`.
* At least one black pixel exists.

## Input

The input is given from Standard Input in the following format:

```
H W
C_{1,1}C_{1,2}...C_{1,W}
C_{2,1}C_{2,2}...C_{2,W}
:
C_{H,1}C_{H,2}...C_{H,W}
```

## Output

Output the image after processing in the following format.

Here, $h$ and $w$ are the height and width of the image after processing, in pixels, respectively.

$c_{i,j}$ is the character representing the color of the pixel at the $i$-th row from the top and $j$-th column from the left; $c_{i,j}$ must be `.` if the pixel is white and `#` if it is black.

```
c_{1,1}c_{1,2}...c_{1,w}
c_{2,1}c_{2,2}...c_{2,w}
:
c_{h,1}c_{h,2}...c_{h,w}
```

## Examples:
### Example 1:
**Sample Output:**
```
4 5
.....
..#..
.###.
.....
```
**Sample Output:**
```
.#.
###
```
**Explaination:**  
You should remove one row from the top edge, one row from the bottom edge, one column from the left edge, and one column from the right edge

### Example 2:
**Sample Input:**
```
3 4
#...
....
...#
```
**Sample Output:**
```
#...
....
...#
```
**Explaination:**  
In this image, all of the topmost row, bottommost row, leftmost column, and rightmost column contain black pixels.  
Therefore, without removing any rows or columns, you should output the original image as is.

### Example 3:
**Sample Input:**
```
5 6
......
......
...#..
......
......
```
**Sample Output:**
```
#
```
