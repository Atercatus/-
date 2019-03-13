#include <vector>
#include <iostream>
#include <string>
using namespace std;


int blockType[4][3][2] = {
	{{0, 0}, {0, 1}, {1, 0}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

bool isPossible(vector<vector<bool>>& board, int y, int x, int type) {
	for (int i = 0; i < 3; i++) {
		int dy = y + blockType[type][i][0];
		int dx = x + blockType[type][i][1];
		//cout <<"dy" << dy << endl << "dx" << dx << endl << "size" << board.size();
		if (0 > dx || dx >= board[0].size() || 0 > dy || dy >= board.size()) {
			return false;
		}
		else if (board[dy][dx]) {
			return false;
		}
	}

	return true;
}

int cover(vector<vector<bool>>& board) {
	bool isEnd = true;
	int x = -1;
	int y = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (!board[i][j]) {
				isEnd = false;
				x = j;
				y = i;
				break;
			}
		}
		if (y != -1)
			break;
	}

	if (isEnd) {
		return 1;
	}
		
	int result = 0;

	for (int i = 0; i < 4; i++) {
		if (isPossible(board, y, x, i)) {
			for (int j = 0; j < 3; j++) {
				int dy = y + blockType[i][j][0];
				int dx = x + blockType[i][j][1];

				board[dy][dx] = true;
			}

			result += cover(board);

			for (int j = 0; j < 3; j++) {
				int dy = y + blockType[i][j][0];
				int dx = x + blockType[i][j][1];

				board[dy][dx] = false;
			}
		}
	}

	return result;
}

int main() {
	int n; // 테스트 케이스 수
	int H; // row
	int W; // col
	string row;
	vector<int> result;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &H, &W);
		vector<vector<bool>> board(H, vector<bool>(W, false));

		for (int j = 0; j < H; j++) {
			cin >> row;
			for (int k = 0; k < row.size(); k++) {
				if (row[k] == '#')
					board[j][k] = true;
				else
					board[j][k] = false;
			}
		}
		result.push_back(cover(board));
	}

	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);
	
	return 0;
}