#include <stdio.h>

#define MAX_SIZE 1001


int main() {
	int c;
	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		int n;
		scanf("%d", &n);

		int scores[MAX_SIZE] = {};
		double sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &scores[j]);
			sum += scores[j];
		}
		int avg = sum / n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (scores[j] > avg)
				sum++;
		}
		printf("%.3f%%\n", sum / n *100);
	}


	return 0;
}