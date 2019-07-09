#include <stdio.h>

#define MAX_SIZE 1000

int scores[MAX_SIZE];

int main() {
	int c;
	scanf("%d", &c);
	double max = 0;
	double sum = 0;

	for (int i = 0; i < c; i++) {
		scanf("%d", &scores[i]);

		if (max < scores[i]) {
			max = scores[i];
		}
	}

	for (int i = 0; i < c; i++) {
		sum += scores[i] / max * 100;
	}

	printf("%.6f\n", sum / c);

	return 0;
}