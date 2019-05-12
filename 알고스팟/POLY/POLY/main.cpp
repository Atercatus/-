#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 101
#define MOD 10000000

int cache[MAX_SIZE][MAX_SIZE];

int poly(int n, int first) {
	if (n == first)
		return 1;

	int &ret = cache[n][first];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int second = 1; n - first >= second; second++) {
		ret = (ret + ((first + second - 1)*(poly(n - first, second))) % MOD) % MOD;
	}

	return ret;
}

int main() {
	int c; // case num
	cin >> c;
	int n;
	vector<int> ret;



	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				cache[i][j] = -1;
			}
		}

		int tmp = 0;
		
		for (int j = 1; j <= n; j++) {
			tmp = (tmp + poly(n, j)) % MOD;
		}
		ret.push_back(tmp);
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}