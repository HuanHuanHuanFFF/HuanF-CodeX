package main

import (
	"sort"
)

func separateSquares(squares [][]int) float64 {
	sort.Slice(squares, func(i, j int) bool {
		a, b := squares[i][1], squares[j][1]
		return a < b
	})
	var sum int64 = 0
	for _, x := range squares {
		sum += int64(x[2]) * int64(x[2])
	}
	var l, r float64 = 0, 1e9
	for r-l > 1e-6 {
		mid := (l + r) / 2
		idx := sort.Search(len(squares), func(i int) bool {
			return float64(squares[i][1]) > mid
		})
		var s float64 = 0
		for i := 0; i < idx; i++ {
			s += min(mid-float64(squares[i][1]), float64(squares[i][2])) * float64(squares[i][2])
		}
		if float64(sum)-s > s {
			l = mid
		} else {
			r = mid
		}
	}
	return r
}
