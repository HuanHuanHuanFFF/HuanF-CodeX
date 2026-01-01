package main

func repeatedNTimes(nums []int) int {
	cnt := make(map[int]int, 2e4)
	for _, x := range nums {
		cnt[x]++
		if cnt[x] == 2 {
			return x
		}
	}
	return -1
}

/*
func repeatedNTimes(nums []int) int {
    n := len(nums)
    for {
        x, y := rand.Intn(n), rand.Intn(n)
        if x != y && nums[x] == nums[y] {
            return nums[x]
        }
    }
}
*/
