# Heuristic Contest 067

## Rank: 

### Story:
Demon King Takahashi has received word that the hero Aoki is approaching his castle. To buy as much time as possible before the hero reaches the throne, the Demon King has decided to renovate the castle by installing linked doors and switches.

However, since the Demon King's army has been infiltrated by a spy working for the hero, the renovation plan is completely known to him. Moreover, the hero is extremely clever, and if the throne is reachable, he will reach it using as few actions as possible. As one of the Demon King's most capable subordinates, you are asked to devise a renovation plan that still delays the hero for as long as possible.

### Problem Statement
There is a Demon King's castle consisting of $N \times N$ cells. Let $(0, 0)$ be the coordinates of the top-left cell, and let $(i, j)$ denote the cell that is $i$ cells downward and $j$ cells to the right from there. 

Each cell is either an empty cell `.` or an obstacle `#`. All cells outside the $N \times N$ grid are regarded as obstacles. Cell $(0, 0)$ contains the entrance, and cell $(N-1, N-1)$ contains the throne. Both of these cells are empty cells. Before the hero enters the castle, you may install **doors** and **switches** inside the castle.

#### Doors
* There are $2K$ types of doors, numbered $0, 1, \dots, 2K - 1$.
* A door can be installed between two orthogonally adjacent cells, and at most $M$ doors may be installed in total.
* At most one door can be installed between the same two cells.

#### Switches
* There are $K$ kinds of switches, numbered $0, 1, \dots, K - 1$.
* At most one switch can be installed in each cell.
* Switches may be installed at the entrance $(0, 0)$ and the throne $(N-1, N-1)$.

#### Linkage Between Doors and Switches
For each $k = 0, 1, \dots, K-1$, door $2k$ and door $2k+1$ are controlled by switch $k$. Initially, door $2k$ is open, and door $2k+1$ is closed. Each time switch $k$ is pressed, the states of door $2k$ and $2k+1$ are swapped.

#### Hero's Actions
The hero enters from $(0, 0)$. On each turn, the hero may:
1. Move to an orthogonally adjacent empty cell (unless a closed door blocks the path).
2. Press a switch on the current cell.

The hero knows the entire placement and will reach the throne using as few actions as possible. You must maximize this minimum number of actions $T$.

### Scoring
The score for a test case is calculated as:
$$\text{round}\left(10^6 \times \log_2 \frac{T}{N}\right)$$
If the hero cannot reach the throne, the score is 1.

### Input Format
```text
N M K
c0
:
cN-1

```

* $N=20, M=50, K=10$ are fixed.
* $c_i$ is a string of length $N$ representing the grid.

### Output Format

1. Output $D$ (number of doors), followed by $D$ lines: `d i j g`
* $d=0$: install door $g$ between $(i, j)$ and $(i+1, j)$
* $d=1$: install door $g$ between $(i, j)$ and $(i, j+1)$


2. Output $S$ (number of switches), followed by $S$ lines: `p q s`
* $p, q$: coordinates of the cell
* $s$: kind of switch

### Input Generation

$N = 20$, $M = 50$, and $K = 10$ are fixed for all test cases.

#### Obstacle Generation Process
1. Start with a grid where all cells are empty. 
2. Arrange the $N^2 - 2$ cells (excluding the entrance $(0, 0)$ and throne $(N - 1, N - 1)$) in a random order.
3. Process each target cell $(i, j)$ in this random order:
    * If at least 3 of the 4 orthogonally adjacent cells are already obstacles, skip this cell. (Cells outside the $N \times N$ grid are counted as obstacles).
    * Otherwise, temporarily change cell $(i, j)$ into an obstacle.
    * If this change makes the remaining empty cells disconnected, revert cell $(i, j)$ back to an empty cell.
    * Otherwise, leave cell $(i, j)$ as an obstacle.

#### Obstacle Reduction Process
1. Arrange all currently generated obstacle cells in a random order.
2. Process each obstacle cell $(i, j)$ in this random order:
    * If at least one of the 4 orthogonally adjacent cells is an empty cell, change cell $(i, j)$ into an empty cell. 
    * Once the total number of obstacle cells changed into empty cells reaches $N$, terminate this process.

### Tools (Input generator and visualizer)
* **Web version:** Provides animations and is more powerful than the local version.
* **Local version:** Requires a Rust compilation environment.
    * *Windows users:* A pre-compiled binary is provided if you are not familiar with the Rust environment.

