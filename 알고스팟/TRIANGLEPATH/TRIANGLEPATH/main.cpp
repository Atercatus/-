#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXHEIGT 100

int height;
int board[MAXHEIGT][MAXHEIGT];
int buffer[MAXHEIGT][MAXHEIGT];

int findPath(int x, int y) {
	if (buffer[y][x] != -1)
		return buffer[y][x];

	int ret = 0;

	if (y == height - 1)
		return board[y][x];

	ret += max(findPath(x, y + 1), findPath(x + 1, y + 1)) + board[y][x];
	buffer[y][x] = ret;

	return ret;
}

int main() {
	int caseNum; // #case
	int size; // board size
	vector<int> ret;

	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {
		// initialization
		for (int i = 0; i < MAXHEIGT; i++) {
			for (int j = 0; j < MAXHEIGT; j++) {
				buffer[i][j] = -1;
				board[i][j] = 0;
			}
		}

		cin >> size;

		for (int y = 0; y < size; y++) {
			height = size;
			for (int x = 0; x <= y; x++) {
				cin >> board[y][x];
			}
		}

		ret.push_back(findPath(0, 0));
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}

