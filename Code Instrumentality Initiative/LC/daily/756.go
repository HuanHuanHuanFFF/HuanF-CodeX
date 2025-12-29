package daily

func pyramidTransition(bottom string, allowed []string) bool {
	top := [6][6][]int{}
	for _, v := range allowed {
		top[v[0]-'A'][v[1]-'A'] = append(top[v[0]-'A'][v[1]-'A'], int(v[2]-'A'))
	}
	n := len(bottom)
	tower := make([][]int, n)
	for i := range n {
		tower[i] = make([]int, i+1)
	}
	for i, s := range bottom {
		tower[n-1][i] = int(s - 'A')
	}
	var dfs func(int, int) bool
	dfs = func(f, x int) bool {
		if f < 0 {
			return true
		}
		if x == f+1 {
			return dfs(f-1, 0)
		}
		for _, t := range top[tower[f+1][x]][tower[f+1][x+1]] {
			tower[f][x] = t
			if dfs(f, x+1) {
				return true
			}
		}
		return false
	}
	return dfs(n-2, 0)
}
