package none

func subarraySum(nums []int, k int) int {
	cnt := make(map[int]int, len(nums))
	sum, ans := 0, 0
	cnt[0] = 1
	for _, num := range nums {
		cnt[num]++
		sum += num
		v := cnt[sum-k]
		ans += v
	}
	return ans
}
