#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 987654321

int cache[10002]; // 10000 까지의 자연수 에다가 string으로 표현하므로 마지막 \0 문자 포함 
string str_pi;

int classify(int begin, int end) {
	int size = end - begin;
	string target = str_pi.substr(begin, size + 1);

	// 모든 숫자가 같을 때
	if (target == string(target.size(), target[0]))
		return 1;

	// 등차 수열
	bool arithmetic = true;
	int diff = target[1] - target[0];
	for (int i = 0; i < target.size() - 1; i++) {
		if (target[i + 1] - target[i] != diff) {
			arithmetic = false;
			break;
		}
	}

	// 차이가 1일 떄
	if (arithmetic && abs(diff) == 1)
		return 2;

	// 교차일 때
	bool alternating = true;
	for (int i = 0; i < target.size(); i++) {
		if (target[i] != target[i % 2]) {
			alternating = false;
			break;
		}
	}

	if (alternating)
		return 4;

	if (arithmetic)
		return 5;
	
	return 10;
}


int memorize(int begin) {
	if (begin == str_pi.size())
		return 0;

	int &ret = cache[begin];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = 3; i <= 5; i++) {
		if (begin + i <= str_pi.size()) {
			ret = min(ret, memorize(begin + i) + classify(begin, begin + i - 1));
		}
	}

	return ret;
}

int main() {
	int c; // number of cases
	cin >> c;
	vector<int> ret;

	for (int i = 0; i < c; i++) {
		// init
		for (int i = 0; i < 10002; i++)
			cache[i] = -1;
	
		cin >> str_pi;

		ret.push_back(memorize(0));

		for (int j = 0; j < str_pi.size(); j++)
			cout << cache[j] << endl;
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}