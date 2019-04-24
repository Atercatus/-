#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_SIZE 100

int cache[MAX_SIZE][MAX_SIZE];
int count_cache[MAX_SIZE][MAX_SIZE];
int board[MAX_SIZE][MAX_SIZE];
int max_len;

int find_max(int x, int y) {
	if (y == max_len) {
		return 0;
	}

	int &ret = cache[y][x];

	if (ret != -1)
		return ret;

	ret = board[y][x];

	ret += max(find_max(x, y + 1), find_max(x + 1, y + 1));

	return ret;
}

int count_max_path(int x, int y) {
	if (y == max_len - 1)
		return 1;

	int &ret = count_cache[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	if (find_max(x, y+1) >= find_max(x+1, y+1))
		ret += count_max_path(x, y + 1);

	if (find_max(x, y+1) <= find_max(x+1, y+1))
		ret += count_max_path(x + 1, y + 1);

	return ret;
}

int main() {
	int c;
	cin >> c;
	vector<int> ret;

	for (int i = 0; i < c; i++) {
		cin >> max_len;

		for (int y = 0; y < max_len; y++) {
			for (int x = 0; x <= y; x++) {
				cache[y][x] = -1;
				count_cache[y][x] = -1;
				cin >> board[y][x];
			}
		}

		find_max(0, 0);
		ret.push_back(count_max_path(0, 0));

	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}