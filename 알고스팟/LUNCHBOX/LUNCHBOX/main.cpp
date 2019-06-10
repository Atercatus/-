#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool sort_by_eatting_time(pair<int, int> &a, pair<int, int> &b) {

	return (a.second > b.second);
}

int schedule(vector<pair<int, int>> &lunchboxes) {
	int ret = 0;
	int size = lunchboxes.size();
	int remain = 0;

	sort(lunchboxes.begin(), lunchboxes.end(), sort_by_eatting_time);

	for (int i = 0; i < size; i++) {
		ret += lunchboxes[i].first;
		remain -= lunchboxes[i].first;
		remain = max(remain, lunchboxes[i].second);
	}
	ret += remain;

	return ret;
}


int main() {
	int c;
	cin >> c;
	vector<int> ret;

	for (int i = 0; i < c; i++) {
		vector<pair<int, int>> lunchboxes;
		vector<int> cooking_times;
		vector<int> eatting_times;
		int participants;
		int cooking_time;
		int eatting_time;

		cin >> participants;
		for (int j = 0; j < participants; j++) {
			cin >> cooking_time;
			cooking_times.push_back(cooking_time);
		}
		for (int j = 0; j < participants; j++) {
			cin >> eatting_time;
			lunchboxes.push_back(make_pair(cooking_times[j], eatting_time));
		}

		ret.push_back(schedule(lunchboxes));
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	return 0;
}