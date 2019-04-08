#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 101

const long long NEGINF = numeric_limits<long long>::min();
int cache[MAX_SIZE][MAX_SIZE];
int A[MAX_SIZE];
int B[MAX_SIZE];
int len_A;
int len_B;


int jlis(int pos_A, int pos_B) {
	int& ret = cache[pos_A + 1][pos_B + 1];

	if (ret != -1)
		return ret;

	ret = 1;

	long long a = pos_A == -1 ? NEGINF : A[pos_A];
	long long b = pos_B == -1 ? NEGINF : B[pos_B];
	long long max_ele = max(a, b);
	
	for (int next_A = pos_A + 1; next_A < len_A; next_A++)
		if (max_ele < A[next_A])
			ret = max(ret, jlis(next_A, pos_B) + 1);

	for (int next_B = pos_B + 1; next_B < len_B; next_B++)
		if (max_ele < B[next_B])
			ret = max(ret, jlis(pos_A, next_B) + 1);

	return ret;
}

int main() {
	int c; // case num
	cin >> c;

	vector<int> ret;

	for (int i = 0; i < c; i++) {
		// init
		for (int y = 0; y < MAX_SIZE; y++) {
			for (int x = 0; x < MAX_SIZE; x++) {
				cache[y][x] = -1;
			}
		}

		cin >> len_A >> len_B;

		for (int j = 0; j < len_A; j++)
			cin >> A[j];
		for (int j = 0; j < len_B; j++)
			cin >> B[j];

		int max_len = jlis(-1, -1) - 1;
		ret.push_back(max_len);
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}