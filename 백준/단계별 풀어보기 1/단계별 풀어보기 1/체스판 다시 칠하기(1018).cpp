#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_SIZE 51

char colors[2] = {'W', 'B'};
char board[MAX_SIZE][MAX_SIZE];

int check(int y, int x) {
	int ret = 987654321;
	for (int k = 0; k < 2; k++) {
		int tmp = 0;

		for (int i = y; i < y + 8; i++) {
			int c = (k + i) % 2;
			char color = colors[c];

			for (int j = x; j < x + 8; j++) {
				if (board[i][j] != color) {
					tmp++;
				}
				color = colors[++c % 2];
			}
		}
		ret = min(ret, tmp);
	}

	return ret;
}

int main() {

	int N, M;
	scanf("%d %d\n", &N, &M);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%c", &board[y][x]);
		}
		char dummy;
		scanf("%c", &dummy);
	}

	int ret = 987654321;

	for (int y = 0; y <= N - 8; y++) {
		for (int x = 0; x <= M - 8; x++) {
			ret = min(ret, check(y,x));
		}
	}

	printf("%d\n", ret);

	return 0;
}