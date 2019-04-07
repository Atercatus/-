#include <iostream>
#include <vector>

using namespace std;

int cache[41][2];

void fibonacci(int n) {
	cache[0][0] = 1;
	cache[0][1] = 0;

	cache[1][0] = 0;
	cache[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		cache[i][0] = cache[i - 1][0] + cache[i - 2][0];
		cache[i][1] = cache[i - 1][1] + cache[i - 2][1];
	}
}

int main() {
	int case_num;
	int input;
	cin >> case_num;

	vector<int> ret;

	for (int i = 0; i < case_num; i++) {
		cin >> input;
	
		fibonacci(input);

		cout << cache[input][0] << " " << cache[input][1] << endl;
	}

	return 0;
}