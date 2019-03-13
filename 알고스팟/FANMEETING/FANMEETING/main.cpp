#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string idols;
	string fans;
	int n;
	vector<int> cvtIdols;
	vector<int> cvtFans;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> idols >> fans;

		for (int j = 0; j < idols.size(); j++) {
			if (idols[i] == 'M') {
				cvtIdols.push_back(1);
			}
			else {
				cvtIdols.push_back(0);
			}
		}

		for (int j = 0; j < fans.size(); j++) {
			if (fans[i] == 'M') {
				cvtFans.push_back(1);
			}
			else {
				cvtFans.push_back(0);
			}
		}
	}
	

	return 0;
}