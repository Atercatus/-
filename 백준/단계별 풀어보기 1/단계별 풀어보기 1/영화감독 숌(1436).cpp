#include <stdio.h>

int getDigitOfNumber(int num) {
	int ret = 0;
	while (num > 0) {
		num /= 10;
		ret++;
	}
	return ret;
}

bool check(int num) {
	bool ret = false;

	while(num > 99){
		int tmp = num;
		int right = tmp % 10;
		tmp /= 10;
		int mid = tmp % 10;
		tmp /= 10;
		int left = tmp % 10;
		tmp /= 10;
		if (right == 6 && mid == 6 && left == 6) {
			ret = true;
		}
		num /= 10;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	int cnt = 0;
	for (int i = 666; i <= 987654321; i++) {
		if (check(i)) {
			cnt++;
		}
		if (cnt == n) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}