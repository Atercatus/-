#include <iostream>
#include <cmath>

using namespace std;

bool cache[10000001];

int main() {
	long long min;
	long long max;

	cin >> min >> max;

	for (int i = 0; i < 10000001; i++)
		cache[i] = true;

	int i = 2;
	if (min == 1) {
		i = 3;
		cache[0] = false;
	}
	for (i; i <= sqrt(max - min); i++) {
		int n = min + i - 2;
		while (n * n <= max) {
			cache[]
		}
	}

	// min이 1일때 구분

	return 0;
}