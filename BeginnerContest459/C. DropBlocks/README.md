# C - Drop Blocks
### Time Limit: 2 sec / Memory Limit: 1024 MiB 

## Score : 300 points

## Description:
There are N cells arranged in a row from left to right. Initially, no blocks are placed in any cell.

You are given Q queries, so process them in order. Each query is one of the following two types:
- `1 x`: Place 1 block in the x-th cell from the left. Then, if every cell has at least 1 block, remove 1 block from every cell.
- `2 y`: Output the number of cells that have at least y blocks.

## Constraints
- 1 ≤ N ≤ 3 × 10<sup>5</sup>
- 1 ≤ Q ≤ 3 × 10<sup>5</sup>
- 1 ≤ x ≤ N
- 1 ≤ y ≤ 3 × 10<sup>5</sup>
- All input values are integers.
- At least one query of the second type exists.

## Input Format:
The input is given from Standard Input in the following format:
```
N Q
query1​
query2​
⋮
queryQ​
```
Each query query<sub>i</sub>​ (1 ≤ i ≤ Q) is given in one of the following formats:
```
1 x
```
```
2 y
```

## Output Format:
Let K be the number of queries of the second type. Output K lines. The i-th line (1 ≤ i ≤ K) should contain the answer to the i-th query of the second type.

## Examples:
### Example 1:
**Sample Input:**
```
3 7
1 1
1 3
1 3
2 1
2 2
1 2
2 1
```
**Sample Output:**
```
2
1
1
```
**Explaination:**  


N=3, and initially the numbers of blocks placed in the 1-st, 2-nd, 3-rd cells from the left are (0,0,0). The queries are processed in order as follows:
- Place 1 block in the 1-st cell from the left. There exist cells with no blocks, so no further action is taken. The numbers of blocks in the 1-st, 2-nd, 3-rd cells become `(1,0,0)`.
- Place 1 block in the 3-rd cell from the left. The numbers of blocks in the 1-st, 2-nd, 3-rd cells become `(1,0,1)`.
- Place 1 block in the 3-rd cell from the left. The numbers of blocks in the 1-st, 2-nd, 3-rd cells become `(1,0,2)`.
- The cells with at least 1 block are the 1-st and 3-rd cells from the left, so there are 2 such cells. Thus, output 2.
- The cells with at least 2 blocks is only the 3-rd cell from the left, so there is 1 such cell. Thus, output 1.
- Place 1 block in the 2-nd cell from the left. At this point, every cell has at least 1 block, so 1 block is removed from every cell. The numbers of blocks in the 1-st, 2-nd, 3-rd cells become `(0,0,1)`.
- The cells with at least 1 block is only the 3-rd cell from the left, so there is 1 such cell. Thus, output 1.

Thus, output 2,1,1 in this order, one per line.
