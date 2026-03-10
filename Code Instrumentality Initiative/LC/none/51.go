package none

func solveNQueens(n int) [][]string {
	ans, g := make([][]string, 0, n), make([][]byte, n)
	for i := 0; i < n; i++ {
		g[i] = make([]byte, n)
		for j := 0; j < n; j++ {
			g[i][j] = '.'
		}
	}
	hor, ax, bx := make([]bool, n), make([]bool, n<<1), make([]bool, n<<1)
	var dfs func(x int)
	dfs = func(x int) {
		if x == n {
			s := make([]string, 0, n)
			for i := 0; i < n; i++ {
				s = append(s, string(g[i]))
			}
			ans = append(ans, s)
			return
		}
		for y := 0; y < n; y++ {
			if !hor[y] && !ax[x+y] && !bx[x+(n-1-y)] {
				g[x][y] = 'Q'
				hor[y], ax[x+y], bx[x+(n-1-y)] = true, true, true
				dfs(x + 1)
				g[x][y] = '.'
				hor[y], ax[x+y], bx[x+(n-1-y)] = false, false, false
			}
		}
	}
	dfs(0)
	return ans
}
