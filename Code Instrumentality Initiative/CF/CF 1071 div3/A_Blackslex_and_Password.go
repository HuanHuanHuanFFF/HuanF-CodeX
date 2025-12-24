package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in1   = bufio.NewReaderSize(os.Stdin, 1<<20)
	out1  = bufio.NewWriterSize(os.Stdout, 1<<20)
	more1 = true
)

func HuanF1() {
	var k, x int
	fmt.Fscan(in1, &k, &x)
	fmt.Fprintf(out1, "%d\n", k*x+1)
}

func main() {
	defer out1.Flush()
	T := 1
	if more1 {
		fmt.Fscan(in1, &T)
	}
	for i := 0; i < T; i++ {
		HuanF1()
	}
}
