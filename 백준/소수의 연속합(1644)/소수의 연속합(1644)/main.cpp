#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 4000001
bool arr[MAX_SIZE] = { 0, };

int main() {
	int n;
	scanf("%d", &n);

	arr[1] = true;

	for (int i = 2; i <= sqrt(MAX_SIZE); i++) {
		if (!arr[i]) {
			for (int j = i * i; j < MAX_SIZE; j += i) {
				arr[j] = true;
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		if (!arr[i]) {
			for (int j = i; sum < n; j++) {
				if (!arr[j]) {
					sum += j;
				}
			}
		}
		ret += sum == n ? 1 : 0;
	}

	printf("%d\n", ret);

	return 0;
}