#include <stdio.h>

bool check(int n) {
	bool ret = true;

	int prev = n % 10;
	n /= 10;
	int cur = n % 10;
	n /= 10;
	int gap = cur - prev;
	prev = cur;
	while (n > 0) {
		cur = n % 10;
		n /= 10;
		if (gap != cur - prev) {
			ret = false;
			break;
		}
		prev = cur;
	}

	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	int ret = 0;
	if (n < 100) {
		ret = n;
	}
	else {
		ret = 99;
		for (int i = 100; i <= n; i++) {
			if (check(i)) {
				ret++;
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}