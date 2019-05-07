#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 101
#define MOD 1000000007LL

long long cache[MAX_SIZE];
int len;

long long put_tile(int width) {
	if (width <= 1)
		return 1;

	long long &ret = cache[width];

	if (ret != -1)
		return ret;

	return ret = (put_tile(width - 2) + put_tile(width - 1)) % MOD;
}

long long find_asymtiling(int width) {
	long long ret = 0;

	if (width % 2 == 1) {
		return ((put_tile(len) - put_tile(width/2) + MOD) % MOD);
	}

	int mid = width / 2;
	ret = put_tile(width);
	ret = (ret - put_tile(mid) + MOD) % MOD;
	ret = (ret - put_tile(mid-1) + MOD) % MOD;
	
	return ret;
}

int main() {
	int c;
	cin >> c;
	vector<long long> ret;

	for (int i = 0; i < c; i++) {
		cin >> len;
		for (int j = 0; j <= len; j++) {
			cache[j] = -1;
		}
		put_tile(len);
		ret.push_back(find_asymtiling(len));
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}