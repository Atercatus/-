#include <string>
#include <iostream>
using namespace std;

const int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
const char board[5][5] = { {'a', 'b', 'c', 'd', 'e'}, {'f', 'g', 'h', 'i', 'j'}, {'k', 'l', 'm', 'n', 'o' }, {'p', 'q', 'r', 's', 't'}, {'u', 'v', 'w', 'x', 'y'} };

bool isRange(int y, int x) {
	if (0 <= y && y < 5 && 0 <= x && x < 5)
		return true;

	return false;
}

bool hasWord(int y, int x, string& word) {
	// 우선 기저 사례부터!!!!
	if (!isRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;

	for (int i = 0; i < 8; i++) {
		if (hasWord(y + dy[i], x + dx[i], word.substr(1)))
			return true;
	}

	return false;
}

int main() {
	char myWord[99999] ;
	scanf_s("%s", myWord, sizeof(myWord));
	string mystr = myWord;

	bool result = false;
	//result = hasWord(0, 0, mystr);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			result = hasWord(i, j, mystr);
			if (result)
				break;
		}
		if (result)
			break;
	}

	printf(result ? "true":"false");

	return 0;
}