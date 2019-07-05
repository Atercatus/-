#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_HOUSE  200001

int houses[MAX_HOUSE];
int N, C;

int getCnt(int distance) {
	int ret = 1;
	int start = houses[0];
	for (int i = 0; i < N; i++) {
		if (houses[i] - start >= distance) {
			ret++;
			start = houses[i];
		}
	}

	return ret;
}

int main() {
	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%d", &houses[i]);
	}

	sort(houses, houses + N);

	int left = 1;
	int right = houses[N - 1] - 1;
	int ret = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = getCnt(mid);

		if (cnt >= C) {
			left = mid + 1;
			ret = mid;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%d\n", ret);

	return 0;
}