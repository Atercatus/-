#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int ret = 0;

	while (n > 0) {
		if (n % 5 == 0) {
			ret += n / 5;
			break;
		}

		n -= 3;
		ret++;
	}

	printf("%d\n", n >= 0? ret : -1);

	return 0;
}