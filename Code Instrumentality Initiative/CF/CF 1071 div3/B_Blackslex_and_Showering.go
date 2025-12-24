// Created by 幻 on 2025/12/24.
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in53   = bufio.NewReaderSize(os.Stdin, 1<<20)
	out53  = bufio.NewWriterSize(os.Stdout, 1<<20)
	more53 = true
)

// HuanF53 B. Blackslex and Showering
func HuanF53() {
	var n int
	fmt.Fscan(in53, &n)
	a := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in53, &a[i])
		if i > 0 {
			d := a[i] - a[i-1]
			if d < 0 {
				d = -d
			}
			sum += d
		}
	}
	var ans int = 1e9
	if d := a[1] - a[0]; d < 0 {
		ans = sum + d
	} else {
		ans = sum - d
	}
	if d := a[n-1] - a[n-2]; d < 0 {
		ans = min(ans, sum+d)
	} else {
		ans = min(ans, sum-d)
	}
	for i := 1; i < n-1; i++ {
		add := a[i-1] - a[i+1]
		if add < 0 {
			add = -add
		}
		s1, s2 := a[i+1]-a[i], a[i]-a[i-1]
		if s1 < 0 {
			s1 = -s1
		}
		if s2 < 0 {
			s2 = -s2
		}
		ans = min(sum-s1-s2+add, ans)
	}
	fmt.Fprintf(out53, "%d\n", ans)
}

func main() {
	defer out53.Flush()
	T := 1
	if more53 {
		fmt.Fscan(in53, &T)
	}
	for i := 0; i < T; i++ {
		HuanF53()
	}
}
