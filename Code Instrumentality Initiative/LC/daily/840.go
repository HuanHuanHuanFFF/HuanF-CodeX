package main

func numMagicSquaresInside(grid [][]int) int {
	isMagic := func(x, y int) bool {
		st := make(map[int]bool, 30)
		sum := grid[x][y] + grid[x+1][y] + grid[x+2][y]
		for i := 0; i < 3; i++ {
			s := 0
			for j := 0; j < 3; j++ {
				val := grid[x+i][y+j]
				if val > 9 || val == 0 {
					return false
				}
				s += val
				if has := st[val]; has {
					return false
				} else {
					st[val] = true
				}
			}
			if s != sum {
				return false
			}
		}
		for i := 0; i < 3; i++ {
			s := 0
			for j := 0; j < 3; j++ {
				val := grid[x+j][y+i]
				s += val
			}
			if s != sum {
				return false
			}
		}
		if s1, s2 := grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2],
			grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y]; s1 == s2 && s1 == sum {
			return true
		}
		return false
	}

	ans, n, m := 0, len(grid), len(grid[0])
	for i := 0; i <= n-3; i++ {
		for j := 0; j <= m-3; j++ {
			if isMagic(i, j) {
				ans++
			}
		}
	}
	return ans
}
