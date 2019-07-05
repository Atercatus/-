#include <stdio.h>

#define MAX_SIZE 10001

int main() {
	int arr[MAX_SIZE];
	int N, X;
	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] < X)
			printf("%d ", arr[i]);
	}

	return 0;
}