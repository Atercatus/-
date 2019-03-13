#include <iostream>
#include <vector>
using namespace std;

bool nums[300000];

/*
// 에라토스테네스의 채
int check(int n) {
	if (n == 1)
		return 1;

	int cnt = 0;

	for (int i = 2; i <= (2*n); i++) {
		if (nums[i] == false)
			continue;

		for (int j = i + i; j <= (2 * n); j += i) {
			nums[j] = false;
		}
	}

	for (int i = n + 1; i <= (2*n); i++) {
		if (nums[i] == true)
			cnt++;
	}

	return cnt;
}
*/
int count(int n) {
	if (n == 1)
		return 1;

	int cnt = 0;

	for (int i = n + 1; i <= (2 * n); i++) {
		if (nums[i] == true)
			cnt++;
	}

	return cnt;
}

int main() {
	for (int i = 0; i < 300000; i++) {
		nums[i] = true;
	}

	for (int i = 2; i <= (250000); i++) {
		if (nums[i] == false)
			continue;

		for (int j = i + i; j <= (250000); j += i) {
			nums[j] = false;
		}
	}

	int n;
	int ret;

	

	while (1) {
		cin >> n;

		if (n == 0)
			break;

		ret = count(n);
		cout << ret << endl;
	}
	
	return 0;
}