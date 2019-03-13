#include <iostream>
#include <vector>
using namespace std;

bool students[10][10];
int students_num;

int countParings(bool picked[10]) {

	int result = 0;
	int firstFree = -1;

	for (int i = 0; i < students_num; i++) {
		if (!picked[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1)
		return 1;


	for (int j = firstFree + 1; j < students_num; j++) {
		if (!picked[firstFree] && !picked[j] && students[firstFree][j]) {
			picked[firstFree] = true;
			picked[j] = true;
			result += countParings(picked);
			picked[firstFree] = false;
			picked[j] = false;
		}
	}

	return result;
}

int main() {
	int n;
	int pairs;
	
	bool m_picked[10];
	vector<int> result;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				students[i][j] = false;

		for (int i = 0; i < 10; i++)
			m_picked[i] = false;

		scanf_s("%d %d", &students_num, &pairs);

		int p1, p2;
		for (int i = 0; i < pairs; i++)
		{
			scanf_s("%d %d", &p1, &p2);
			students[p1][p2] = true;
			students[p2][p1] = true;
		}

		result.push_back(countParings(m_picked));
	}

	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);

	return 0;
}

