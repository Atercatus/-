#include <stdio.h>

// a >= b;
long long extended_euclidean(long long a, long long b) {
	long long r = b;
	long long old_r = a;
	long long s = 0;
	long long old_s = 1;
	long long t = 1;
	long long old_t = 0;

	while (r != 0) {
		long long q = old_r / r;
		
		long long tmp = r;
		r = old_r - r*q;
		old_r = tmp;

		tmp = s;
		s = old_s - s*q;
		old_s = tmp;

		tmp = t;
		t = old_t - t*q;
		old_t = tmp;
	}

	// old_r is gcd
	if (old_r != 1)
		old_t = -1;

	long long ret[2] = { old_s, old_t}; // Bezout coefficients

	return ret[1]; // ¿ª¿ø
}

int main() {
	long long N = 0, A = 0;
	scanf("%lld %lld", &N, &A);

	long long inverse = extended_euclidean(N, A);
	if (inverse < -1)
		inverse += N;

	printf("%lld %lld\n", N - A, inverse);

	return 0;
}