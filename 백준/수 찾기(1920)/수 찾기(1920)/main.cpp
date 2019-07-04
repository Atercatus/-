#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_NUM 100001
int *arr;
int N;

bool findNum(int num) {
	int left = 0;
	int right = N;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] < num) {
			left = mid + 1;
		}
		else if (arr[mid] > num) {
			right = mid - 1;
		}
		else {
			return true;
		}
	}

	return false;
}

int main() {
	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);

		printf("%d\n", findNum(tmp));
	}

	return 0;
}