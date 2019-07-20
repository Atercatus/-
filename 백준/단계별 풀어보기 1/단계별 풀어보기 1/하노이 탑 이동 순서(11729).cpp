#include <stdio.h>
#include <math.h>

void move(int from, int to) {
	printf("%d %d\n", from, to);
	return;
}

void hanoi(int n, int from, int temp, int to) {
	if (n == 1) {
		move(from, to);
		return;
	}
	
	hanoi(n - 1, from, to, temp);
	move(from, to);
	hanoi(n - 1, temp, from, to);

	return;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)pow((double)2, (double)n) - 1);
	hanoi(n, 1, 2, 3);

	return 0;
}