/* Requires Thread Building Blocks (libtbb-dev on Debian) */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <execution>
#include <iostream>

typedef struct { int a, b; } pair_t;
pair_t a[ARRAYSIZE];

int main(void) {
	srand(time(NULL));
	for (auto &x : a) {
		x.a = rand() % 1000000;
		x.b = rand() % 1000000;
	}

	struct timespec begin;
	clock_gettime(CLOCK_MONOTONIC, &begin);

	std::sort(std::execution::par, a, a+ARRAYSIZE,
		[](const pair_t &x, const pair_t &y) {
			int d = x.a - y.a;
			return d < 0 || (d == 0 && x.b > y.b);
		});

	struct timespec end;
	clock_gettime(CLOCK_MONOTONIC, &end);
	double time = end.tv_sec - begin.tv_sec +
		(end.tv_nsec - begin.tv_nsec) / 1000000000.0;

	std::cout << "(" << a[ARRAYSIZE/2].a << ") C++ time for " << ARRAYSIZE
		<< " pairs (parallel): " << time << "s\n";
}
