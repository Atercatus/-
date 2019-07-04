#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1000001

int main() {
	int left = 0;
	int right = 0;

	scanf("%d %d", &left, &right);

	bool arr[MAX_SIZE] = { 0, };
	arr[1] = 1;

	for (int i = 2; i <= sqrt(MAX_SIZE); i++) {
		if (!arr[i]) {
			for (int j = i*i; j < MAX_SIZE; j += i) {
				arr[j] = true;
			}
		}
	}

	for (int i = left; i <= right; i++) {
		if (!arr[i])
			printf("%d\n", i);
	}

	return 0;
}