#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

#define INF 123456789

int coins[100]; // 사용가능한 동전들
int n; // 동전 가짓수
int k; // 총 합

int buffer[10001]; // 금액에 맞는 최소값

int check(int balance) {
	if (balance < 0)
		return INF;

	if (balance == 0)
		return 0;

	int ret = buffer[balance];

	if (ret != -1)
		return buffer[balance];

	ret = INF;

	// 가능한 모든 코인에 대해서 반복
	for (int i = 0; i < n; i++) {
		ret = min(check(balance - coins[i]) + 1, ret);
	}

	if (ret <= INF)
		buffer[balance] = ret;

	return ret;
}

int main() {
	// initialization
	memset(buffer, -1, sizeof(buffer));

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &coins[i]);
	}

	int ret = check(k);

	if (ret == 0 || ret == INF)
		ret = -1;

	cout << ret << endl;

	return 0;
}