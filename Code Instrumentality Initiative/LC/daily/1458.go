package main

func maxDotProduct(nums1 []int, nums2 []int) int {
	l1, l2 := len(nums1), len(nums2)
	f := make([][]int, l1+1)
	for i := 0; i <= l1; i++ {
		f[i] = make([]int, l2+1)
	}
	for i := 0; i <= l1; i++ {
		for j := 0; j <= l2; j++ {
			f[i][j] = -1e9
		}
	}
	for i := 1; i <= l1; i++ {
		for j := 1; j <= l2; j++ {
			f[i][j] = max(f[i-1][j-1]+nums1[i-1]*nums2[j-1],
				nums1[i-1]*nums2[j-1], f[i][j], f[i-1][j], f[i][j-1])
		}
	}
	return f[l1][l2]
}
