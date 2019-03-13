#include <iostream>
#include <string>
using namespace std;

string s;
int n;

string make(string input) {
	string ret = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == ' ') {
			ret += "%20";
			continue;
		}
		ret += s[i];
	}

	return ret;
}

int main() {
	/*
	getline(cin, s);
	cin >> n;
	string ret = make(s);
	cout << ret;
	*/
	string test = "asdasd aw \0 asdad";
	cout << test;

		/*
	char c[2] = {'%', '20'};
	for (int i = 0; i < 2; i++)
		cout << c[i] << endl;

*/		
}