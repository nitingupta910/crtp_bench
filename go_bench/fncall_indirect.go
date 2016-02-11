package main

import (
	"fmt"
)

type Fooer interface {
	tick(n uint64)
}

type foo struct {
	counter uint64
}

func (f *foo) tick(n uint64) {
	f.counter += n
}

const N uint64 = 40000

func runLoop(f Fooer) {
	var i, j uint64
	for i = 0; i < N; i++ {
		for j = 0; j < i; j++ {
			f.tick(j)
		}
	}
}

func main() {
	var f foo
	runLoop(&f)
	fmt.Println(f.counter)
}
