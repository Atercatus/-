#include <iostream>
#include <algorithm>

using namespace std;

#define INF 123456789

int cache[1000001];


int make_one(int input) {
	int& ret = cache[input];

	if(ret != INF) {
		return ret;
	}

	if (ret == 1) {
		return 0;
	}

	// 3·Î ³ª´«´Ù
	if (input % 3 == 0) {
		ret = min(ret, make_one(input / 3) + 1);
	}

	// 2·Î ³ª´«´Ù
	if (input % 2 == 0) {
		ret = min(ret, make_one(input / 2) + 1);
	}

	// 1À» »«´Ù
	ret = min(ret, make_one(input - 1) + 1);

	return ret;
}

int main() {
	// init
	cache[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		cache[i] = INF;
	}

	int input;

	cin >> input;

	int ret = make_one(input);

	cout << ret << endl; 

	return 0;
}