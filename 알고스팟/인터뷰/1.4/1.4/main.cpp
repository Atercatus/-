#include<iostream>
#include<string>

using namespace std;

char cache[280];

string check(string input) {
	int index, check = 0;
	for (int i = 0; i < input.size(); i++) {
		index = input[i] - 'a';
		cache[index] += 1;
	}

	for (int i = 0; i < 280; i++) {
		if (cache[i] % 2 == 1) {
			check++;
			if (check > 1)
				return "False";
		}
	}

	return "True";
}

int main() {
	string input = "";
	string ret = "";

	getline(cin, input);
	ret = check(input);
	cout << ret;

	return 0;
}