#include <iostream>
#include <set>
#include <vector>

using namespace std;

int order(vector<int> &russians, vector<int> &koreans) {
	multiset<int> ratings(koreans.begin(), koreans.end());
	int ret = 0;

	for (int i = 0; i < russians.size(); i++) {
		if (*ratings.rbegin() < russians[i]) {
			ratings.erase(ratings.begin());
		}
		else {
			ratings.erase(ratings.lower_bound(russians[i]));
			ret++;
		}
	}

	return ret;
}

int main() {
	int c;
	cin >> c;

	int n;
	vector<int> ret;

	for (int i = 0; i < c; i++) {
		vector<int> koreans;
		vector<int> russians;
		cin >> n;
		int korean;
		int russian;
		for (int j = 0; j < n; j++) {
			cin >> russian;
			russians.push_back(russian);
		}
		for (int j = 0; j < n; j++) {
			cin >> korean;
			koreans.push_back(korean);
		}

		ret.push_back(order(russians, koreans));
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	return 0;
}