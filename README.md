The Curiously Recurring Template Pattern in C++

All C++ source code from:
http://eli.thegreenplace.net/2011/05/17/the-curiously-recurring-template-pattern-in-c

Also contains benchmark for direct/indirect functional call overhead in Go in go_bench/

----------

## Numbers:
 * N=40000
 * iMac (Retina 5K, 27-inch, Late 2014) - 3.5 GHz Intel Core i5
 * best of 3 runs

### C++ benchmarks
```
time ./direct`

counter=10665866680000

real    0m0.003s
user    0m0.001s
sys     0m0.001s
```

```
time ./crtp

counter=10665866680000

real    0m0.003s
user    0m0.001s
sys     0m0.001s
```

```
time ./dynamic

counter=10665866680000

real    0m1.284s
user    0m1.273s
sys     0m0.002s
```

### Go benchmarks

```
time ./fncall_none

counter: 10665866680000

real    0m0.222s
user    0m0.213s
sys     0m0.003s
```

```
time ./fncall

counter: 10665866680000

real    0m1.422s
user    0m1.413s
sys     0m0.004s
```

```
time ./fncall_indirect

counter: 10665866680000

real    0m1.675s
user    0m1.664s
sys     0m0.004s
```
