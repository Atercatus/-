#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

#define INF 123456789

int coins[100]; // ��밡���� ������
int n; // ���� ������
int k; // �� ��

int buffer[10001]; // �ݾ׿� �´� �ּҰ�

int check(int balance) {
	if (balance < 0)
		return INF;

	if (balance == 0)
		return 0;

	int ret = buffer[balance];

	if (ret != -1)
		return buffer[balance];

	ret = INF;

	// ������ ��� ���ο� ���ؼ� �ݺ�
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