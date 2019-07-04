#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_WOODS_NUM 1000001
#define MAX_WOOD_HEIGHT 2000000000

int woods[MAX_WOODS_NUM] = {};
int N, K;

long long getWood(long long height) {
	long long ret = 0;
	for (int i = 0; i < N; i++) {
		ret += woods[i] >= height ? woods[i] - height : 0;
	}
	return ret;
}

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &woods[i]);
	}

	sort(woods, woods + N);

	int left = 0;
	int right = woods[N-1];
	int ret = 0;
	long long sum = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		sum = getWood(mid);

		if (sum < K) {
			right = mid - 1;
		}
		else if (sum > K) {
			left = mid + 1; 
			ret = mid;
		}
		else {
			ret = mid;
			break;
		}
	}

	printf("%d\n", ret);

	return 0;
}