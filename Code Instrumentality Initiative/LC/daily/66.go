package main

import "slices"

func plusOne(digits []int) []int {
	n := len(digits)
	slices.Reverse(digits)
	digits[0]++
	for i := 0; i < n; i++ {
		if i != n-1 {
			digits[i+1] += digits[i] / 10
			digits[i] %= 10
		} else {
			if digits[i] >= 10 {
				digits = append(digits, digits[i]/10)
				digits[i] %= 10
			}
		}
	}
	slices.Reverse(digits)
	return digits
}
