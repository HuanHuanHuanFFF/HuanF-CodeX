package daily

func bestClosingTime(customers string) int {
	n := len(customers)
	pre, suf := make([]int, n+1), make([]int, n+2)
	for i, x := range customers {
		if x == 'N' {
			pre[i+1] = pre[i] + 1
		} else {
			pre[i+1] = pre[i]
		}
	}
	for i := n; i >= 1; i-- {
		if customers[i-1] == 'Y' {
			suf[i] = suf[i+1] + 1
		} else {
			suf[i] = suf[i+1]
		}
	}
	m, idx := int(1e9), 0
	for i := 1; i <= n+1; i++ {
		if now := pre[i-1] + suf[i]; now < m {
			m = now
			idx = i - 1
		}
	}
	return idx
}
