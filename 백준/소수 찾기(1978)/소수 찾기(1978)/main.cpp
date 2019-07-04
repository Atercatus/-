#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1001

// 반대로하기

int main() {
	int n;
	scanf("%d", &n);

	bool arr[MAX_SIZE] = { 0, };
	memset(arr, true, sizeof(arr));
	arr[1] = false;
	int m = sqrt(MAX_SIZE);

	for(int i = 2; i <= m; i++) {
		for (int j = i * i; j < MAX_SIZE; j += i) {
			arr[j] = false;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		if (arr[tmp])
			ret++;
	}

	printf("%d\n", ret);

	return 0;
}