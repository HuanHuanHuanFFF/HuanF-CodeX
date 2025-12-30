package main

func countNegatives(grid [][]int) int {
	ans, n, m := 0, len(grid), len(grid[0])
	x, y := 0, m
	back := 0
	for x < n && y >= 0 {
		for y > 0 && grid[x][y-1] < 0 {
			y--
			back++
		}
		ans += back
		x++
	}
	return ans
}
