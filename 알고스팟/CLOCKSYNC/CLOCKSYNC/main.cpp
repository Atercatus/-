#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 9999999;
const bool switches_clocks[10][16] = {
	{ true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false },
	{ false, false, false, true, false, false, false, true, false, true, false, true, false, false, false, false },
	{ false, false, false, false, true, false, false, false, false, false, true, false, false, false, true, true },
	{ true, false, false, false, true, true, true, true, false, false, false, false, false, false, false, false },
	{ false, false, false, false, false, false, true, true, true, false, true, false, true, false, false, false },
	{ true, false, true, false, false, false, false, false, false, false, false, false, false, false, true, true },
	{ false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, true },
	{ false, false, false, false, true, true, false, true, false, false, false, false, false, false, true, true },
	{ false, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false },
	{ false, false, false, true, true, true, false, false, false, true, false, false, false, true, false, false },
};

bool isCorrect(int clocks[]) {
	for (int i = 0; i < 16; i++) {
		if (clocks[i] != 12)
			return false;
	}

	return true;
}

void setTime(int clocks[], int switch_num) {
	for (int i = 0; i < 16; i++) {
		if (switches_clocks[switch_num][i] == true) {
			clocks[i] += 3;
			if (clocks[i] == 15)
				clocks[i] = 3;
		}
	}
}

int solve(int clocks[], int switch_num) {
	if (switch_num == 10) {
		return isCorrect(clocks) ? 0 : INF;
	}

	int result = INF;

	for (int i = 0; i < 4; i++) {
		result = min(result, solve(clocks, switch_num + 1) + i);
		setTime(clocks, switch_num);
	}

	return result;
}


int main() {
	int n; // case num
	int clocks[16] = { 0, };
	vector<int> result;

	scanf("%d", &n);

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < 16; i++) {
			scanf("%d", &clocks[i]);
		}

		result.push_back(solve(clocks, 0));
	}

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] >= INF) {
			cout << -1 << endl;
			continue;
		}
		cout << result[i] << endl;
	}

	return 0;
}
