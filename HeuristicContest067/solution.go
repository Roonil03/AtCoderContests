package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = NewFastScanner()
	out = bufio.NewWriter(os.Stdout)
)

type FastScanner struct {
	r *bufio.Reader
}

func NewFastScanner() *FastScanner {
	return &FastScanner{r: bufio.NewReaderSize(os.Stdin, 1<<20)}
}

func (fs *FastScanner) rInt() int {
	sign, val := 1, 0
	c, err := fs.r.ReadByte()
	for (c < '0' || c > '9') && c != '-' {
		if err != nil {
			return 0
		}
		c, err = fs.r.ReadByte()
	}
	if c == '-' {
		sign = -1
		c, _ = fs.r.ReadByte()
	}
	for c >= '0' && c <= '9' {
		val = val*10 + int(c-'0')
		c, err = fs.r.ReadByte()
		if err != nil {
			break
		}
	}
	return sign * val
}

func (fs *FastScanner) rString() string {
	buf := make([]byte, 0, 16)
	c, err := fs.r.ReadByte()
	for c == ' ' || c == '\n' || c == '\r' || c == '\t' {
		if err != nil {
			return ""
		}
		c, err = fs.r.ReadByte()
	}
	for c != ' ' && c != '\n' && c != '\r' && c != '\t' {
		buf = append(buf, c)
		c, err = fs.r.ReadByte()
		if err != nil {
			break
		}
	}
	return string(buf)
}

type Cut struct {
	d     int
	edges [][4]int
}

func solve() {
	n := in.rInt()
	m := in.rInt()
	k := in.rInt()
	if n == 0 {
		return
	}
	grid := make([]string, n)
	for i := 0; i < n; i++ {
		grid[i] = in.rString()
	}
	dist := make([][]int, n)
	for i := 0; i < n; i++ {
		dist[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dist[i][j] = -1
		}
	}
	q := [][2]int{{0, 0}}
	dist[0][0] = 0
	dirs := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for len(q) > 0 {
		cur := q[0]
		q = q[1:]
		r, c := cur[0], cur[1]
		for _, d := range dirs {
			nr, nc := r+d[0], c+d[1]
			if nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == '.' && dist[nr][nc] == -1 {
				dist[nr][nc] = dist[r][c] + 1
				q = append(q, [2]int{nr, nc})
			}
		}
	}
	if dist[n-1][n-1] == -1 {
		fmt.Fprintln(out, 0)
		fmt.Fprintln(out, 0)
		return
	}
	var candidates []Cut
	for d := 0; d < dist[n-1][n-1]; d++ {
		var edges [][4]int
		for r := 0; r < n; r++ {
			for c := 0; c < n; c++ {
				if grid[r][c] != '.' || dist[r][c] == -1 {
					continue
				}
				if r+1 < n && grid[r+1][c] == '.' && dist[r+1][c] != -1 {
					u, v := dist[r][c], dist[r+1][c]
					if (u <= d && v > d) || (v <= d && u > d) {
						edges = append(edges, [4]int{r, c, r + 1, c})
					}
				}
				if c+1 < n && grid[r][c+1] == '.' && dist[r][c+1] != -1 {
					u, v := dist[r][c], dist[r][c+1]
					if (u <= d && v > d) || (v <= d && u > d) {
						edges = append(edges, [4]int{r, c, r, c + 1})
					}
				}
			}
		}
		if len(edges) > 0 && len(edges) <= m {
			candidates = append(candidates, Cut{d, edges})
		}
	}
	sort.Slice(candidates, func(i, j int) bool {
		return len(candidates[i].edges) < len(candidates[j].edges)
	})
	var selected []Cut
	tEdges := 0
	for _, cut := range candidates {
		if len(selected) == k {
			break
		}
		if tEdges+len(cut.edges) <= m {
			selected = append(selected, cut)
			tEdges += len(cut.edges)
		}
	}
	sort.Slice(selected, func(i, j int) bool {
		return selected[i].d < selected[j].d
	})
	fg := make([][]bool, n)
	for i := 0; i < n; i++ {
		fg[i] = make([]bool, n)
	}
	type DoorOut struct {
		da, ia, ja, ga int
	}
	type SwitchOut struct {
		pb, qb, sb int
	}
	var do []DoorOut
	var sw []SwitchOut
	for i, cut := range selected {
		g := 2*i + 1
		for _, e := range cut.edges {
			r1, c1, r2 := e[0], e[1], e[2]
			da := 0
			if r1 == r2 {
				da = 1
			}
			do = append(do, DoorOut{da, r1, c1, g})
		}
		rd := make([][]int, n)
		for r := 0; r < n; r++ {
			rd[r] = make([]int, n)
			for c := 0; c < n; c++ {
				rd[r][c] = -1
			}
		}
		rq := [][2]int{}
		for _, e := range cut.edges {
			r1, c1, r2, c2 := e[0], e[1], e[2], e[3]
			if dist[r1][c1] <= cut.d && rd[r1][c1] == -1 {
				rd[r1][c1] = 0
				rq = append(rq, [2]int{r1, c1})
			}
			if dist[r2][c2] <= cut.d && rd[r2][c2] == -1 {
				rd[r2][c2] = 0
				rq = append(rq, [2]int{r2, c2})
			}
		}
		for len(rq) > 0 {
			cur := rq[0]
			rq = rq[1:]
			r, c := cur[0], cur[1]
			for _, d := range dirs {
				nr, nc := r+d[0], c+d[1]
				if nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == '.' && dist[nr][nc] <= cut.d && rd[nr][nc] == -1 {
					rd[nr][nc] = rd[r][c] + 1
					rq = append(rq, [2]int{nr, nc})
				}
			}
		}
		r1, c1, mm := -1, -1, -2
		for r := 0; r < n; r++ {
			for c := 0; c < n; c++ {
				if grid[r][c] == '.' && dist[r][c] <= cut.d && !fg[r][c] {
					if rd[r][c] > mm {
						mm = rd[r][c]
						r1, c1 = r, c
					}
				}
			}
		}
		if r1 != -1 {
			fg[r1][c1] = true
			sw = append(sw, SwitchOut{r1, c1, i})
		}
	}
	fmt.Fprintln(out, len(do))
	for _, d := range do {
		fmt.Fprintln(out, d.da, d.ia, d.ja, d.ga)
	}
	fmt.Fprintln(out, len(sw))
	for _, s := range sw {
		fmt.Fprintln(out, s.pb, s.qb, s.sb)
	}
}

func main() {
	out = bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()
	solve()
}
