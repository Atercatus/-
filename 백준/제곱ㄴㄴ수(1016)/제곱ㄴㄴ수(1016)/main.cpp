#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAX_SIZE 1000001

bool cache[MAX_SIZE];

long long findNoNoSquare(long long min, long long max) {
	long long cnt = 0;

	for (long long i = 2; i <= sqrt(max); i++) {
		long long square = i * i;
		long long start = min;
		if (start % square != 0) {
			start = (start / square + 1) * square;
		}

		for (long long next = start; next <= max; next += square) {
			if (!cache[next - min]) {
				cache[next - min] = true;
				cnt++;
			}
		}
	}

	return max - min + 1 - cnt;
}

int main() {
	long long min;
	long long max;

	cin >> min >> max;

	for (long long i = 0; i < MAX_SIZE; i++)
		cache[i] = false;

	cout << findNoNoSquare(min, max) << endl;

	return 0;
}