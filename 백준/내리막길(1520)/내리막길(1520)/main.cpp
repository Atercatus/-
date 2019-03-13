#include <iostream>

using namespace std;

#define MAXSIZE 500

int board[MAXSIZE][MAXSIZE];
int buffer[MAXSIZE][MAXSIZE];
int pathCnt; // 경로 숫자
int maxY;
int maxX;

int move(int x, int y) {
	// base 
	if ((y == maxY - 1) && (x == maxX - 1)) {
		return 1;
	}
	
	if (buffer[y][x] != -1) {

		return buffer[y][x];
	}

	int ret = 0;

	// up
	if ((y - 1 >= 0) && board[y - 1][x] < board[y][x]) {
		ret += move(x, y - 1);
	}
	// down
	if ((y + 1 < maxY) && board[y + 1][x] < board[y][x]) {
		ret += move(x, y + 1);
	}
	// left
	if ((x - 1 >= 0) && board[y][x - 1] < board[y][x]) {
		ret += move(x - 1, y);
	}
	// right
	if ((x + 1 < maxX) && board[y][x + 1] < board[y][x]) {
		ret += move(x + 1, y);
	}

	buffer[y][x] = ret;
	return ret;
}

int main() {
	//initialization
	pathCnt = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++) {
			board[i][j] = -1;
			buffer[i][j] = -1;
		}
	}

	cin >> maxY >> maxX;

	for (int y = 0; y < maxY; y++) {
		for (int x = 0; x < maxX; x++) {
			cin >> board[y][x];
		}
	}

	pathCnt = move(0, 0);

	cout << pathCnt << endl;

	return 0;
}