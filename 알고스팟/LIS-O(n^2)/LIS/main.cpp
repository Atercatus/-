#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_SIZE 500

int cache[MAX_SIZE];
int list[MAX_SIZE];
int length;

int lis(int pos) {
	int& ret = cache[pos];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int next = pos + 1; next < length; next++) {
		if (list[pos] < list[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}

	return ret;
}

int main() {
	int c; // #case num

	cin >> c;
	
	vector<int> ret;

	for (int i = 0; i < c; i++) {
		// initialization
		for (int i = 0; i < MAX_SIZE; i++) {
			cache[i] = -1;
		}
		cin >> length;
		for (int j = 0; j < length; j++) {
			cin >> list[j];
		}


		int maxLen = 0;
		for (int k = 0; k < length - 1; k++) {
			maxLen = max(lis(k), maxLen);
		}
		ret.push_back(maxLen);
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	return 0;
}