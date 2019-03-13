#include<iostream>
using namespace std;

int fastSum(int n) {
	if (n == 1) return 1;
	if (n % 2 == 1) return fastSum(n - 1) + n;

	return 2 * fastSum(n / 2) + (n*n) / 4;
}

int main() {
	int n;
	cin >> n;
	int ret = fastSum(n);

	cout << ret << endl;

	return 0;
}
// �ð����⵵: O(logn) <n�� ������ ǥ���� �ڸ��� + ù�ڸ��� �����ϰ� ��Ÿ���� 1�� ����>