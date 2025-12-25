// Created by 幻 on 2025/12/25.
package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

var (
	in14   = bufio.NewReaderSize(os.Stdin, 1<<20)
	out14  = bufio.NewWriterSize(os.Stdout, 1<<20)
	more14 = true
)

// HuanF14 C. Blackslex and Number Theory
func HuanF14() {
	var n int
	fmt.Fscan(in14, &n)
	a := make([]int, n)
	for i, _ := range a {
		fmt.Fscan(in14, &a[i])
	}
	slices.Sort(a)
	fmt.Fprintf(out14, "%d\n", max(a[0], a[1]-a[0]))
}

func main() {
	defer out14.Flush()
	T := 1
	if more14 {
		fmt.Fscan(in14, &T)
	}
	for i := 0; i < T; i++ {
		HuanF14()
	}
}
