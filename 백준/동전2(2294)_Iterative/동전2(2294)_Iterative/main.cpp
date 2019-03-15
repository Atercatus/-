#include <stdio.h>
#include <algorithm>

using namespace std;

#define INF 987654321

int coins[101];
int cache[10001];

int main() {
	int n; // 동전 개수
	int k; // 총합
	
	cache[0] = 0;
	for (int i = 1; i < 10001; i++) {
		cache[i] = INF;
	}

	scanf_s("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &coins[i]);
	}

	for (int i = 0; i < n; i++) {
		int tmp = coins[i];
		for (int j = coins[i]; j <= k; j++) {
			cache[j] = min(cache[j - tmp] + 1, cache[j]);
		}
	}

	int ret = cache[k] >= INF ? -1 : cache[k];

	printf("%d\n", ret);

	return 0;
}
