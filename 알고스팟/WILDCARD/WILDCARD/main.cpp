#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXSIZE 100

int buffer[MAXSIZE][MAXSIZE]; // [wild][f_str]
string wild, f_str;

bool match(int w_pos, int s_pos) {
	if (buffer[w_pos][s_pos] != -1) {
		return buffer[w_pos][s_pos];
	}

	// 둘 다 끝까지 도달
	if (w_pos >= wild.size() && s_pos >= f_str.size())
		return true;

	bool ret = false;

	if (wild[w_pos] == '*') {
		ret = match(w_pos + 1, s_pos) || match(w_pos, s_pos + 1);
	} 

	// 한쪽만 끝까지 도달
	if ((w_pos >= wild.size() || s_pos >= f_str.size())) {
		return ret;
	}

	if (wild[w_pos] == '?') {
		ret = match(w_pos + 1, s_pos + 1) || ret;
	}

	if (wild[w_pos] == f_str[s_pos])
		ret = match(w_pos + 1, s_pos + 1) || ret;

	buffer[w_pos][s_pos] = ret;

	return ret;
}

int main() {
	int caseNum; // #case
	int fileNum; // #file

	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {
		vector<string> ret; // result

		cin >> wild;
		cin >> fileNum;

		for (int j = 0; j < fileNum; j++) {
			// initialization
			for (int i = 0; i < MAXSIZE; i++) {
				for (int j = 0; j < MAXSIZE; j++) {
					buffer[i][j] = -1;
				}
			}

			cin >> f_str;
			if (match(0, 0))
				ret.push_back(f_str);
		}

		sort(ret.begin(), ret.end());

		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << endl;
		}
	}

	return 0;
}