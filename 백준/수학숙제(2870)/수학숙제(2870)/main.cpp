#pragma warning(disable:4996)

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr;

bool compare(const string& s1, const string& s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}

	return s1.compare(s2) < 0;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		input.append("#");
		string tmp = "";

		for (int j = 0; j < input.length(); j++) {
			if ('0' <= input[j] && input[j] <= '9') {
				tmp = tmp + input[j];
				continue;
			}
			if (tmp.length() > 0) {
				int idx;
				for (idx = 0; tmp[idx] == '0'; idx++) {}
				if (idx == tmp.length())
					idx--;

				tmp.erase(0, idx);
				arr.push_back(tmp);
				tmp = "";
			}
		}
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}

	return 0;
}