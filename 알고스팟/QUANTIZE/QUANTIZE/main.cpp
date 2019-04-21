#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LEN 101
#define MAX_REMAIN 11
#define INF 987654321

int cache[MAX_LEN][MAX_REMAIN];
int len_of_sequance;

// 수열의 합
int sum_of_sequance[MAX_LEN];
// 수열의 제곱합
int sum_of_square[MAX_LEN];

// input: 수열(sequance)
void preset(int seq[]) {
	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_REMAIN; j++) {
			cache[i][j] = -1;
		}
	}

	sort(seq, seq + len_of_sequance);

	sum_of_sequance[0] = seq[0];
	sum_of_square[0] = seq[0] * seq[0];

	for (int i = 0; i < len_of_sequance; i++) {
		sum_of_sequance[i + 1] = sum_of_sequance[i] + seq[i+1];
		sum_of_square[i + 1] = sum_of_square[i] + (seq[i+1] * seq[i+1]);
	}
}

// SIG(A^2) - 2*m*SIG(A) + (m^2)*size
int calc_SSE(int begin, int end) {
	int ret = 0;
	int size = end - begin + 1;
	int seq_sum = sum_of_sequance[end] - (begin == 0 ? 0 : sum_of_sequance[begin - 1]);
	int square_sum = sum_of_square[end] - (begin == 0 ? 0 : sum_of_square[begin - 1]);

	int mean = (int)((0.5 + double(seq_sum) / size));

	ret = (square_sum) - (2 * mean * (seq_sum)) + (mean * mean * size);

	return ret;
}

int quantize(int begin, int remains) {
	if (begin == len_of_sequance)
		return 0;

	int &ret = cache[begin][remains];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int next = 1; next + begin <= len_of_sequance; next++) {
		if (remains > 0)
			ret = min(ret, calc_SSE(begin, begin + next - 1) + quantize(begin + next, remains - 1));
	}

	return ret;
}

int main() {
	int num_of_case;
	cin >> num_of_case;
	vector<int> ret;
	int remains = 0;
	int seq[MAX_LEN];

	for (int i = 0; i < num_of_case; i++) {
		cin >> len_of_sequance >> remains;

		for (int j = 0; j < len_of_sequance; j++) {
			cin >> seq[j];
		}

		preset(seq);
		ret.push_back(quantize(0, remains));
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}


	return 0;
}