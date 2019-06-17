// 모든 상자가 90도 회전이 가능하므로 상자 3개를 배치하는 방법에는
// 1. 3개의 상자를 하나의 열에 배치한다
// 2. 2개의 상자를 두개의 열에 배치하고 그 위에 나머지 상자를 배치한다.
// !! 3개의 상자를 3열에 배치하는 것은 90도 회전하여 하나의 열에 배치하는 것과 같다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 987654321

typedef struct Rect{
	int width;
	int height;
}rect;

rect presents[6];

int one_col(int a, int b, int c) {
	int ret = 0;
	ret = (max(max(presents[a].width, presents[b].width), presents[c].width)) * (presents[a].height + presents[b].height + presents[c].height);

	return ret;
}

int two_col(int a, int b, int c) {
	int ret = 0;
	ret = (max(presents[a].width + presents[b].width, presents[c].width)) * (max(presents[a].height, presents[b].height) + presents[c].height);

	return ret;
}

int main() {
	int case_num;
	vector<int> ret;
	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		int case_ret = INF;
		for (int j = 0; j < 3; j++) {
			cin >> presents[j].height >> presents[j].width;
			presents[j + 3].width = presents[j].height;
			presents[j + 3].height = presents[j].width;
		}

		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				for (int l = 0; l < 6; l++) {
					if (j % 3 == k % 3 || k % 3 == l % 3 || l % 3 == j % 3)
						continue;
					case_ret = min(case_ret, one_col(j, k, l));
					case_ret = min(case_ret, two_col(j, k, l));
				}
			}
		}

		ret.push_back(case_ret);
	}

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	return 0;
}