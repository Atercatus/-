#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD 20000
#define MAX_CASE 50

int h[MAX_BOARD];

int getMax(int op1, int op2) {
	if (op1 < op2)
		return op2;

	return op1;
}

int findMax(int start, int end) {
	if (start == end)
		return h[start];

	int ret = 0;
	int mid = (start + end) / 2;

	// left
	ret = getMax(ret, findMax(start, mid));
	// right
	ret = getMax(ret, findMax(mid + 1, end));

	// middle
	int left = mid;
	int right = mid;
	int height = h[mid];

	while (start < left || right < end){
		if (right < end && (left == start || h[left - 1] < h[right + 1])) {
			right++;
			if (height > h[right])
				height = h[right];
		}

		else {
			left--;
			if (height > h[left])
				height = h[left];
		}
		ret = getMax(ret, (right - left + 1) * height);
	}

	return ret;
}

int main() {
	int n; // number of cases
	int boardNum; // number of boards
	int height = 0;
	int* ret = (int*)malloc(sizeof(int)*MAX_CASE);


	scanf("%d", &n);
	for (int i = 0, j = 0; i < n; i++) {
		scanf("%d", &boardNum);
		for (j = 0; j < boardNum; j++) {
			scanf("%d", &height);
			h[j] = height;
		}

		*(ret + i) = findMax(0, j - 1);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d\n", *(ret + i));
	}
}