#include <string>
#include <iostream>

using namespace std;

bool check(string str1, string str2) {
	int length = (str1.length() > str2.length()) ? str1.length() : str2.length();

	int cnt = 0;
	int idx1 = 0;
	int idx2 = 0;

	if (str1.length() != str2.length())
		cnt++;

	for (; idx1 < str1.length() && idx2 < str2.length(); ){
		if (str1[idx1] == str2[idx2])
		{
			idx1++; idx2++;
		}
		else if (str1[idx1] == str2[idx2+1]) {
			idx1++;
			idx2 += 2;
			cnt++;
		}
		else if (str1[idx1 + 1] == str2[idx2]) {
			idx1 += 2;
			idx2++;
			cnt++;
		}
		else {
			idx1++;
			idx2++;
			cnt++;
		}

		if (cnt >= 2) {
			return false;
		}
	}
	return true;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	bool ret = check(str1, str2);

	cout << ret << endl;

	return 0;
}