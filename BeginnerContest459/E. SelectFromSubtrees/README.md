# E - Select from Subtrees
### Time Limit: 2 sec / Memory Limit: 1024 MiB 
## Score : 450 points
## Description:
There is a rooted tree T with N vertices, where the vertices are numbered as vertex 1, vertex 2, …, vertex N.
Vertex 1 is the root of T, and the (direct) parent of vertex i (2 ≤ i ≤ N) is P<sub>i</sub>​.

Additionally, vertex i (1 ≤ i ≤ N) has C<sub>i</sub>​ candies. All (C<sub>1</sub> ​+ C<sub>2</sub> ​+ ⋯ + C<sub>N</sub>​) candies are distinguishable from each other.

Takahashi gave instructions to N squirrels. Specifically, he gave the following instruction to the i-th squirrel (1 ≤ i ≤ N):

- Choose and collect D<sub>i</sub>​ candies from the subtree rooted at vertex i.

Different squirrels cannot take the same candy.
Output the number, modulo `998244353`, of possible ways to choose the candies.

Here, even if the set of candies ultimately chosen is the same, if the squirrels that chose them are different, they are counted as different ways.
If it is impossible for all squirrels to bring back candies as instructed, output 0.

## Constraints
- 2 ≤ N ≤ 2 × 10<sup>5</sup>
- 1 ≤ P<sub>i</sub> ​≤ N
- 1 ≤ C<sub>i</sub> ​≤ 10<sup>9</sup>
- 1 ≤ D<sub>i​</sub>
- D<sub>1</sub>​ + D<sub>2</sub> ​+ ⋯ + D<sub>N</sub> ≤ 10<sup>6</sup>
- All input values are integers.
- T is a rooted tree with vertex 1 as the root.

## Input Format:
The input is given from Standard Input in the following format:
```
N
P2​ P3​ … PN​
C1​ C2​ … CN​
D1​ D2​ … DN​
```
## Output Format:
Output the number, modulo `998244353`, of possible ways to choose the candies.

## Examples:
### Example 1:
**Sample Input:**
```
5
1 1 3 3
1 2 1 2 3
1 1 3 1 1
```
**Sample Output:**
```
144
```
**Explaination:**  
We call the candies so that we have candy 1 at vertex 1, candies 2,3 at vertex 2, candy 4 at vertex 3, candies 5,6 at vertex 4, and candies 7,8,9 at vertex 5.

One possible way to choose the candies is as follows:
- Squirrel 1 collects candy 3 from the tree rooted at vertex 1 (consisting of vertices 1,2,3,4,5).
- Squirrel 2 collects candy 2 from the tree rooted at vertex 2 (consisting of vertex 2).
- Squirrel 3 collects candies 4,7,9 from the tree rooted at vertex 3 (consisting of vertices 3,4,5).
- Squirrel 4 collects candy 6 from the tree rooted at vertex 4 (consisting of vertex 4 only).
- Squirrel 5 collects candy 8 from the tree rooted at vertex 5 (consisting of vertex 5 only).

Note that this is counted as a different way from the following:
- Squirrel 1 collects candy 2 from the tree rooted at vertex 1 (consisting of vertices 1,2,3,4,5).
- Squirrel 2 collects candy 3 from the tree rooted at vertex 2 (consisting of vertex 2).
- Squirrel 3 collects candies 4,7,9 from the tree rooted at vertex 3 (consisting of vertices 3,4,5).
- Squirrel 4 collects candy 6 from the tree rooted at vertex 4 (consisting of vertex 4 only).
- Squirrel 5 collects candy 8 from the tree rooted at vertex 5 (consisting of vertex 5 only).

There are 144 valid ways in total, so output 144 modulo 998244353, that is, 144.

### Example 2:
**Sample Input:**
```
3
3 1
1000000000 1 1
1 1 1
```
**Sample Output:**
```
1755647
```
**NOTE:** Remember to output the count modulo `998244353`.