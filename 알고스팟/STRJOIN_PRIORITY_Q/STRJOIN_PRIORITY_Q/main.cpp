#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // priority_queue
#include <functional> // greater

using namespace std;

int join(vector<int> &lengths) {
	int ret = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < lengths.size(); i++) {
		pq.push(lengths[i]);
	}

	while (pq.size() > 1) {
		int tmp = pq.top();
		pq.pop(); 
		tmp += pq.top();
		pq.pop();
		ret += tmp;
		pq.push(tmp);
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

