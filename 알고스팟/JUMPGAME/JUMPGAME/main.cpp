#include <iostream>
#include <vector>

using namespace std;

int cache[100][100];
int board[100][100];
int maxSize;

bool jump(int x, int y) {
	bool ret = false;

	if ((x == maxSize -1) && (y == maxSize-1)) // end point
		return true;

	if (cache[y][x] != -1)
		return cache[y][x];

	if ((x + board[y][x]) < maxSize) { // 오른쪽 이동이 가능함
		/*if (jump(x + board[y][x], y))
			ret = true;*/
		ret = ret || jump(x + board[y][x], y);
	}
	if ((y + board[y][x]) < maxSize) { // 아래쪽 이동이 가능함
		/*if (jump(x, y + board[y][x]))
			ret = true;*/
		ret = ret || jump(x, y + board[y][x]);
	}
	cache[y][x] = ret;

	return ret;
}

int main() {
	int n; // case num
	int boardSize; // board size
	int tmp;
	vector<bool> ret;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> boardSize;
		maxSize = boardSize;
		for (int y = 0; y < boardSize; y++) {
			for (int x = 0; x < boardSize; x++) {
				cin >> tmp;
				board[y][x] = tmp;
				cache[y][x] = -1;
			}
		}

		ret.push_back(jump(0, 0));
	}

	for (int i = 0; i < ret.size(); i++) {
		switch (ret[i]) {
		case true:
			cout << "YES" << endl;
			break;
		case false:
			cout << "NO" << endl;
			break;
		}
	}
}