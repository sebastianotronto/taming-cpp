# Taming C++

Experiments with C++ and comparisons with C.

## sort-benchmark

For the
[first post in the series](https://sebastiano.tronto.net/blog/2024-04-30-taming-cpp-motivation/).

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

## raii

For the
[second post in the series](https://sebastiano.tronto.net/blog/2024-12-26-taming-cpp-raii/).

Various small examples on constructors, destructors and related things.
