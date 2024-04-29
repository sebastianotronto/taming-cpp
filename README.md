# Taming C++

Experiments with C++ and comparisons with C.

## sort-benchmark

Inspired by [Bert's post](https://berthub.eu/articles/posts/c++-1).

Sorting an array of integers is a simple task, so C and C++ should perform
similarly, right? Wrong!

```
C time for 100000000 numbers: 9.886314s
C++ time for 100000000 numbers: 4.92299s
C++ time for 100000000 numbers (parallel): 0.495435s
```

A similar benchmark is provided for sorting an arrays of pairs in a
non-standard way.
