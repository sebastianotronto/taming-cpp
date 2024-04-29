#define _POSIX_C_SOURCE 200809L /* Required to use clock_gettime */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { int a, b; } pair_t;
pair_t a[ARRAYSIZE];

int compar(const void *x, const void *y) {
	pair_t *p = (pair_t *)x;
	pair_t *q = (pair_t *)y;
	int d = p->a - q->a;
	return d > 0 ? 1 : (d < 0 ? -1 : (q->b - p->b));
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < ARRAYSIZE; i++) {
		a[i].a = rand() % 1000000;
		a[i].b = rand() % 1000000;
	}

	struct timespec begin;
	clock_gettime(CLOCK_MONOTONIC, &begin);

	qsort(a, ARRAYSIZE, sizeof(pair_t), compar);

	struct timespec end;
	clock_gettime(CLOCK_MONOTONIC, &end);
	double time = end.tv_sec - begin.tv_sec +
		(end.tv_nsec - begin.tv_nsec) / 1000000000.0;

	printf("(%d) C time for %d pairs: %lfs\n",
		a[ARRAYSIZE/2].a, ARRAYSIZE, time);

	return 0;
}
