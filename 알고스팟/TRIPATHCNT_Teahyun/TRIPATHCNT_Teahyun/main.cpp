#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX_SIZE 101

int max_len;

int board[MAX_SIZE][MAX_SIZE];
int max_val[MAX_SIZE][MAX_SIZE];
int cnt[MAX_SIZE][MAX_SIZE];

int find_max_cnt() {
	for (int y = 0; y < max_len; y++) {
		for (int x = 0; x <= y; x++) {
			int cur = max_val[y][x];
			int bott = board[y + 1][x];
			int rightbott = board[y + 1][x + 1];
			int sum = cur + bott;

			if (max_val[y + 1][x] == sum)
				cnt[y + 1][x] += cnt[y][x];

			else {
				max_val[y + 1][x] = sum < max_val[y + 1][x] ? max_val[y + 1][x] : sum;
				cnt[y + 1][x] = sum < max_val[y + 1][x] ? cnt[y + 1][x] : cnt[y][x];
			}

			max_val[y + 1][x + 1] = cur + rightbott;
			cnt[y + 1][x + 1] = cnt[y][x];

		}
	}

	int answer = 0;
	int v_max = 0;
	for (int i = 0; i < max_len; i++)
	{
		if (max_val[max_len - 1][i] > v_max) {
			v_max = max_val[max_len - 1][i];
			answer = cnt[max_len - 1][i];
		}
		else if (max_val[max_len - 1][i] == v_max) {
			answer += cnt[max_len - 1][i];
		}
	}

	return answer;
}

int main()
{
	int c;
	cin >> c;

	vector<int> ret;

	for (int i = 0; i < c; i++)
	{
		cin >> max_len;

		// init
		for (int i = 0; i < max_len; i++) {
			for (int j = 0; j <= i; j++) {
				cnt[i][j] = 1;
			}
		}

		int tmp = 0;
		for (int y = 0; y < max_len; y++) {
			for (int x = 0; x <= y; x++) {
				cin >> tmp;
				board[y][x] = tmp;
				max_val[y][x] = tmp;
			}
		}

		ret.push_back(find_max_cnt());
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
}