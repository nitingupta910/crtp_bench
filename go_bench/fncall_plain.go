package main

import (
	"fmt"
)

const N uint64 = 40000

func tick(counter, n uint64) uint64 {
	return counter + n
}

func runLoop() uint64 {
	var i, j, counter uint64
	for i = 0; i < N; i++ {
		for j = 0; j < i; j++ {
			counter = tick(counter, j)
		}
	}
	return counter
}

func main() {
	fmt.Println("counter:", runLoop())
}
