#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

bool n_available[10] = {0, };

int getNumberOfDigits(int num) {
	int ret = 0;
	
	if (num == 0) {
		return 1;
	}

	while (num > 0) {
		num /= 10;
		ret++;
	}
	return ret;
}


bool check(int channel) {
	bool ret = true;
	int size = getNumberOfDigits(channel);

	for (int i = 0; i < size; i++) {
		int d = channel % 10;
		channel /= 10;
		if (n_available[d]) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main() {
	int channel;
	int n;
	scanf("%d %d", &channel, &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		n_available[tmp] = true;
	}

	int ret = 987654321;
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int tmp = getNumberOfDigits(i);
			tmp += abs(channel - i);
			ret = min(ret, tmp);
		}
	}
	ret = min(ret, abs(channel - 100));

	printf("%d\n", ret);

	return 0;
}