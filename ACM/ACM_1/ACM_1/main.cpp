#include <vector>
#include <iostream>

using namespace std;

vector<int> cache;

int happy(int num) {
	int tmp = 0; 
	int ret = 0;

	while(num != 0) {
		tmp = num % 10;
		ret += tmp * tmp;
		num /= 10;
	}

	return ret;
}

bool check(int num) {
	for (int i = 0; i < cache.size(); i++){
		if (num == cache[i])
			return false;
	}

	cache.push_back(num);

	return true;
}

int main() {
	int n;

	cin >> n;
	int ret = n;

	while (true) {
		ret = happy(ret);
		if (ret == 1)
			break;

		if (!check(ret)) {
			cout << "UNHAPPY" << endl;
			return 0;
		}
	}

	cout << "HAPPY" << endl;

	return 0;
}