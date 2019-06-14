#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int join(vector<int> &lengths) {
	int ret = 0;
	while (lengths.size() > 1) {
		sort(lengths.begin(), lengths.end());
		int tmp = *lengths.begin() + *(lengths.begin() + 1);
		ret += tmp;
		lengths.erase(lengths.begin());
		lengths.erase(lengths.begin());
		lengths.push_back(tmp);
	}

	return ret;
}

int main() {
	int c;
	cin >> c;
	vector<int> ret;

	for (int i = 0; i < c; i++) {
		vector<int> lengths;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			lengths.push_back(tmp);
		}
		ret.push_back(join(lengths));
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	return 0;
}

