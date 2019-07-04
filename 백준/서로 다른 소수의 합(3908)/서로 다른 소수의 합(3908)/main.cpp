#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

#define MAX_SUM 1121
#define MAX_K 15

vector<int> primes;
int cache[MAX_SUM][MAX_K];

void extractPrimes() {
	bool arr[MAX_SUM] = {};
	for (int i = 2; i <= sqrt(MAX_SUM); i++) {
		if (!arr[i]) {
			for (int j = i * i; j < MAX_SUM; j += i) {
				arr[j] = true;
			}
		}
	}

	for (int i = 2; i < MAX_SUM; i++) {
		if (!arr[i])
			primes.push_back(i);
	}
}

void makeCache() {
	cache[0][0] = 1;

	for (int i = 0; i < primes.size(); i++) {
		for (int n = MAX_SUM - 1; n >= primes[i]; n--) {
			for (int k = 1; k < MAX_K; k++) {
				cache[n][k] += cache[n - primes[i]][k - 1];
			}
		}
	}
}

int main() {
	extractPrimes();
	makeCache();

	int c;
	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		int n, k;
		scanf("%d %d", &n, &k);

		printf("%d\n", cache[n][k]);
	}

	return 0;
}