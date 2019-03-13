#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_BOARD 20000
int h[MAX_BOARD];


int findMax(int start, int end) {
	if (start == end)
		return h[start];

	int ret = 0;
	int mid = (start + end) / 2;

	//left
	ret = max(ret, findMax(start, mid));
	//right	
	ret = max(ret, findMax(mid + 1, end));

	// middle
	int left = mid;
	int right = mid;
	int height = h[mid];
	while (start < left || right < end) {
		if (right < end && (h[left - 1] < h[right + 1] || left == start )) {
			right++;
			if (height > h[right])
				height = h[right];
		}

		else {
			left--;
			if (height > h[left])
				height = h[left];
		}

		ret = max(ret, (right - left + 1)*height);
	}

	return ret;
}

int main() {
	int n = 0;
	int boardNum = 0;
	int height = 0;
	vector<int> ret;

	cin >> n;
	for (int i = 0, j = 0; i < n; i++) {
		cin >> boardNum;
		for (j = 0; j < boardNum; j++) {
			cin >> height;
			h[j] = height;
		}
		ret.push_back(findMax(0, j-1));
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	return 0;
}