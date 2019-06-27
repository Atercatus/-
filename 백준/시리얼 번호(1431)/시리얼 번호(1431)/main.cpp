#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

bool isDigit(char c) {
	return '0' <= c && c <= '9';
}

bool compare(const string& str1, const string& str2) {
	if (str1.length() != str2.length ()) {
		return str1.length() < str2.length();
	}

	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < str1.length(); i++) {
		sum1 += isDigit(str1[i]) ? str1[i] - '0' : 0;
		sum2 += isDigit(str2[i]) ? str2[i] - '0' : 0;
	}
	if (sum1 != sum2)
		return sum1 < sum2;

	return str1 < str2;
}

int main() {
	int n;
	scanf("%d", &n);
	string input[1000];

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	std::sort(input, input + n, compare);

	for (int i = 0; i < n; i++) {
		cout << input[i] << endl;
	}
	
	return 0;
}