package main

import "slices"

func maximumHappinessSum(happiness []int, k int) int64 {
	slices.Sort(happiness)
	slices.Reverse(happiness)
	ans := int64(0)
	for i := 0; i < k; i++ {
		ans += int64(max(happiness[i]-i, 0))
	}
	return ans
}
