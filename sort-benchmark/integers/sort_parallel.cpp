/* Requires Thread Building Blocks (libtbb-dev on Debian) */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <execution>
#include <iostream>

int a[ARRAYSIZE];

int main(void) {
	srand(time(NULL));
	for (auto &x : a) x = rand() % 1000000000;

	struct timespec begin;
	clock_gettime(CLOCK_MONOTONIC, &begin);

	std::sort(std::execution::par, a, a+ARRAYSIZE,
		[](const int &x, const int &y) { return x < y; });

	struct timespec end;
	clock_gettime(CLOCK_MONOTONIC, &end);
	double time = end.tv_sec - begin.tv_sec +
		(end.tv_nsec - begin.tv_nsec) / 1000000000.0;

	std::cout << "(" << a[ARRAYSIZE/2] << ") C++ time for " << ARRAYSIZE
		<< " numbers (parallel): " << time << "s\n";
}
