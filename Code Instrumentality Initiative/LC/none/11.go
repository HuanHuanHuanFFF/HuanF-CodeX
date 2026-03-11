package none

func maxArea(height []int) int {
	l, r, ans := 0, len(height)-1, 0
	for l < r {
		ans = max(ans, (r-l)*min(height[l], height[r]))
		if height[l] > height[r] {
			r--
		} else {
			l++
		}
	}
	return ans
}
