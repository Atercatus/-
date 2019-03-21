#include <iostream>
#include <cmath>

using namespace std;

// �����佺�׳׽��� ü�� 10,000,000 ������ ���ڿ��� ����


int main() {
	bool* numbers = new bool[10000000];
	int N = 7;
	for (int i = 0; i <= N; i++) {
		numbers[i] = true;
	}
	long long answer = 0;

	for (int i = 2; i <= sqrt(N); i++) {
		if (numbers[i]) {

			for (int j = i*2; j <= N; j += i) {
				numbers[j] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (numbers[i])
			answer += i;
	}

	cout << answer << endl;

	return 0;
}