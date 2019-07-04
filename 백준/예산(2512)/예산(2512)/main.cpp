#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_CITY 10000

int cities[MAX_CITY];
int N;


long long getSum(int bound) {
	long long ret = 0;
	for (int i = 0; i < N; i++) {
		if (cities[i] < bound) {
			ret += cities[i];
		}
		else {
			ret += bound;
		}
	}
	return ret;
}


int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &cities[i]);
	}
	long long budget;
	scanf("%lld", &budget);

	int left = 1;
	int right = 0;
	for (int i = 0; i < N; i++) {
		right = max(right, cities[i]);
	}

	long long sum = 0;
	int mid = 0;
	int ret = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		sum = getSum(mid);

		if (sum < budget) {
			left = mid + 1;
			ret = mid;
		}
		else if (sum > budget) {
			right = mid - 1;
		}
		else {
			ret = mid;
			break;
		}
	}

	printf("%d\n", ret);

	return 0;
}