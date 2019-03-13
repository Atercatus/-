#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool list[5001]; // 물건개수

//vector<int> picked;
vector<int> pickList;
int n; // 원소 개수
int w; // weight
string corr = "NO"; 

void pick(int cnt, int ret, int start) {
	if (cnt == 0) {
		if(ret == 0)
			corr = "YES";

		//return ret;
		return;
	}

	int tmp= -1;

	for (int i = start; i < n; i++) {
		if (list[i] == true)
		{
			tmp = i;
			break;
		}
	}

	if (tmp == -1)
		return;

	for (int i = tmp; i < n; i++) {
		if (list[i] == true) {
			list[i] = false;
			pick(cnt - 1, ret - pickList[i], i);
			list[i] = true;
		}
	}

	//return ret;
}

int main() {
	cin >> w >> n;

	for (int i = 0; i < n; i++)
		list[i] = true;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pickList.push_back(tmp);
	}

	pick(4, w, 0);

	cout << corr << endl;

	return 0;
}