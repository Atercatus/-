#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

#define MAX_PRIME 1299710

bool arr[MAX_PRIME] = { 0, };

int main() {
	int n;
	scanf("%d", &n);
	vector<int> ret;
	arr[1] = true;

	for (int i = 2; i <= sqrt(MAX_PRIME); i++) {
		if (!arr[i]) {
			for (int j = i *i; j < MAX_PRIME; j += i) {
				arr[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		int left = num;
		int right = num;

		while (arr[right]) {
			right++;
		}
		while (arr[left]) {
			left--;
		}
		ret.push_back(right - left);
	}

	for (int i = 0; i < ret.size(); i++) {
		printf("%d\n", ret[i]);
	}

	return 0;
}