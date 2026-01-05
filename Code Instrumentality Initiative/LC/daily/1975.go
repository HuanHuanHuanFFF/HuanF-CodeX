package main

func maxMatrixSum(matrix [][]int) int64 {
	var ans int64 = 0
	cnt, mi := 0, 1000_07
	for _, m := range matrix {
		for _, x := range m {
			if x < 0 {
				x = -x
				cnt++
			}
			if mi > x {
				mi = x
			}
			ans += int64(x)
		}
	}
	if cnt%2 == 1 {
		ans -= int64(mi) * 2
	}
	return ans
}
