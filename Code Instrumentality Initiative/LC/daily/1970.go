package main

import "fmt"

func latestDayToCross(row int, col int, cells [][]int) int {
	g := make([][]bool, row+1)
	for i := 1; i <= row; i++ {
		g[i] = make([]bool, col+1)
	}

	type p struct{ x, y int }
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}
	bfs := func() bool {
		vis := make([][]bool, row+1)
		for i := 1; i <= row; i++ {
			vis[i] = make([]bool, col+1)
		}
		q := make([]p, col*row)
		head := 0
		for i := 1; i <= col; i++ {
			if !g[1][i] {
				q = append(q, p{1, i})
				vis[1][i] = true
			}
		}
		for head < len(q) {
			x, y := q[head].x, q[head].y
			if x == row {
				return true
			}
			head++
			for i := 0; i < 4; i++ {
				nx, ny := x+dx[i], y+dy[i]
				if nx >= 1 && nx <= row && ny >= 1 && ny <= col && !g[nx][ny] && !vis[nx][ny] {
					q = append(q, p{nx, ny})
					vis[nx][ny] = true
				}
			}
		}
		return false
	}

	l, r, last := -1, len(cells), 0
	for l+1 < r {
		mid := (l + r) >> 1
		if last < mid {
			for i := last; i < mid; i++ {
				g[cells[i][0]][cells[i][1]] = true
			}
		} else {
			for i := last - 1; i >= mid; i-- {
				g[cells[i][0]][cells[i][1]] = false
			}
		}
		if bfs() {
			l = mid
		} else {
			r = mid
		}
		last = mid
	}
	return l
}

func main() {
	row := 3
	col := 3
	cells := [][]int{
		{1, 2},
		{2, 1},
		{3, 3},
		{2, 2},
		{1, 1},
		{1, 3},
		{2, 3},
		{3, 2},
		{3, 1},
	}
	fmt.Print(latestDayToCross(row, col, cells))
}
