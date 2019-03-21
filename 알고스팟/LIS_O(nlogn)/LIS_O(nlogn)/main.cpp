#include <vector>
#include <iostream>

using namespace std;

#define MAX_SIZE 501
#define INF 123456789

int list[MAX_SIZE];
int n; // #ele num


int lower_bound(int left, int right, int target, vector<int>& ret) {
	while (right - left > 0) {
		int mid = (right + left) / 2;
		if (ret[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return right + 1;
}

int lis() {
	vector<int> ret;
	ret.push_back(-INF);
	for (int i = 1; i <= n; i++) {
		if (ret.back() >= list[i]) {
			int idx = lower_bound(1, ret.size()-1, list[i], ret) -1;
			ret[idx] = list[i];
		}
		else {
			ret.push_back(list[i]);
		}
	}
	
	return ret.size() - 1;
}


int main() {
	int c; // #case num
	vector<int> ret;

	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> list[j];
		}

		ret.push_back(lis());
	}

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}