CC = gcc
CPP = g++
OPT = -O3
VAR = -DARRAYSIZE=100000000

all: sort_c sort_cpp sort_parallel_cpp

sort_c:
	${CC} ${OPT} ${VAR} -std=c11 -o sort sort.c
	./sort

sort_cpp:
	${CPP} ${OPT} ${VAR} -std=c++20 -o sort sort.cpp 
	./sort

sort_parallel_cpp:
	${CPP} ${OPT} ${VAR} -std=c++20 -o sort sort_parallel.cpp -ltbb
	./sort

.PHONY: sort_c sort_cpp sort_parallel_cpp
