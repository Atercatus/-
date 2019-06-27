#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_SIZE 200001

int total = 0;
int sameColorTotal[MAX_SIZE] = { 0, };
int ret[MAX_SIZE] = { 0, };

typedef struct {
	int idx;
	int size;
	int color;
}Ball;
Ball input[MAX_SIZE];

bool compare(Ball b1, Ball b2) {
	return b1.size < b2.size;
}

int main() {
	int n;
	scanf("%d", &n);



	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &input[i].color, &input[i].size);
		input[i].idx = i;
	}

	sort(input + 1, input + n + 1, compare);

	for (int i = 1, j = 1; i <= n; i++) {
		for (; input[j].size < input[i].size; j++) {
			total += input[j].size;
			sameColorTotal[input[j].color] += input[j].size;
		}
		ret[input[i].idx] = total - sameColorTotal[input[i].color];
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", ret[i]);
	}

	return 0;
}