#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 101

long long cache[MAX_SIZE];
int len;

long long put_tile(int begin) {
	if (begin == len)
		return 1;

	long long &ret = cache[begin];

	if (ret != -1)
		return ret;

	ret = 0;

	ret += put_tile(begin + 1);

	if(begin + 2 <= len)
		ret += put_tile(begin + 2);

	return ret % 1000000007;
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
		ret.push_back((put_tile(0)));
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
}