#include <string>
#include <iostream>
#include <vector>
using namespace std;

string reverse(string::iterator &it) {
	char head = *(it);
	string ret = "";

	if (head == 'w' || head == 'b') {
		ret += head;
	}

	else {
		string leftTop = reverse(++it);
		string rightTop = reverse(++it);
		string leftBot = reverse(++it);
		string rightBot = reverse(++it);

		ret += 'x' + leftBot + rightBot + leftTop + rightTop;
	}

	return ret;
}

int main() {
	int caseNum;
	string input;
	vector<string> ret;

	cin >> caseNum;

	for (int i = 0; i < caseNum; i++) {
		cin >> input;
		string::iterator it = input.begin();
		ret.push_back(reverse(it));
	}

	for (int i = 0; i < caseNum; i++) {
		cout << ret[i] << endl;
	}

	return 0;
}