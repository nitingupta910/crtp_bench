package main

import (
	"fmt"
)

const N uint64 = 40000

func runLoop() uint64 {
	var i, j, counter uint64
	for i = 0; i < N; i++ {
		for j = 0; j < i; j++ {
			counter += j
		}
	}
	return counter
}

func main() {
	fmt.Println(runLoop())
}
