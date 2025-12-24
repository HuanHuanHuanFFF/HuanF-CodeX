package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in   = bufio.NewReaderSize(os.Stdin, 1<<20)
	out  = bufio.NewWriterSize(os.Stdout, 1<<20)
	more = true
)

func HuanF() {
}

func main() {
	defer out.Flush()
	T := 1
	if more {
		fmt.Fscan(in, &T)
	}
	for i := 0; i < T; i++ {
		HuanF()
	}
}
