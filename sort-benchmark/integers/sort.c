#define _POSIX_C_SOURCE 200809L /* Required to use clock_gettime */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[ARRAYSIZE];

int compar(const void *x, const void *y) { return *(int *)x - *(int *)y; }

int main() {
	srand(time(NULL));
	for (int i = 0; i < ARRAYSIZE; i++) a[i] = rand() % 1000000000;

	struct timespec begin;
	clock_gettime(CLOCK_MONOTONIC, &begin);

	qsort(a, ARRAYSIZE, sizeof(int), compar);

	struct timespec end;
	clock_gettime(CLOCK_MONOTONIC, &end);
	double time = end.tv_sec - begin.tv_sec +
		(end.tv_nsec - begin.tv_nsec) / 1000000000.0;

	printf("(%d) C time for %d numbers: %lfs\n",
		a[ARRAYSIZE/2], ARRAYSIZE, time);

	return 0;
}
