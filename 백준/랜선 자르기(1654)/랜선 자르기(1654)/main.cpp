#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

using namespace std;

// 1~ ���� �� �߿����� �ּڰ����̿��� �̺�Ž��
// ������ ���� ������ ��ǥġ���� ������ right ����
// ������ ���� ������ ��ǥġ���� ������ left ����

#define MAX_K 10001
#define MAX_N 1000000

int N, K;
int lines[MAX_K];

int getLines(long long threshold) {
	int ret = 0;
	for (int i = 0; i < K; i++) {
		ret += (lines[i] / threshold);
	}

	return ret;
}

int main() {
	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%d", &lines[i]);
	}

	sort(lines, lines + K);

	long long left = 1;
	long long right = lines[K-1];
	long long ret = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = getLines(mid);

		if (cnt < N) {
			right = mid - 1;
		}
		else if (cnt >= N) {
			left = mid + 1;
			ret = mid;
		}
	}

	printf("%d\n", ret);

	return 0;
}