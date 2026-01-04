package main

func sumFourDivisors(nums []int) int {
	ans := 0
	for _, x := range nums {
		cnt := 0
		sum := 0
		for i := 1; i*i <= x; i++ {
			if x%i == 0 {
				if i*i == x {
					cnt++
				} else {
					cnt += 2
				}
				sum += i + x/i
			}
		}
		if cnt == 4 {
			ans += sum
		}
	}
	return ans
}
