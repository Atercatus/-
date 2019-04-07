#include <iostream>
#include <algorithm>

using namespace std;

int make_one(int input) {
	int ret = 0;
	
	if (input < 2) {
		return 0;
	}
	
	ret = min(make_one(input / 3) + input % 3 + 1, make_one(input / 2) + input % 2 + 1);

	return ret;
}

int main() {
	int input = 0;
	cin >> input;

	int ret = make_one(input);

	cout << ret << endl;

	return 0;
}