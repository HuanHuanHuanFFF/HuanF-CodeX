package main

func minTimeToVisitAllPoints(points [][]int) int {
	ans := 0
	abs := func(x int) int {
		if x > 0 {
			return x
		} else {
			return -x
		}
	}
	for i := 1; i < len(points); i++ {
		ans += max(abs(points[i][0]-points[i-1][0]), abs(points[i][1]-points[i-1][1]))
	}
	return ans
}
