#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int testcase, N;
	int triangle[101][101];
	int count[101][101];
	int maxValue[101][101];
	cin >> testcase;
	for (int cycle = 0; cycle < testcase; cycle++)
	{
		cin >> N;
		for (int i = 1; i < 101; i++) {
			for (int j = 1; j <= i; j++) {
				count[i][j] = 1;
				maxValue[i][j] = 0;
			}
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= i; j++)
				cin >> triangle[i][j];

		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= i; j++) {
				if (maxValue[i + 1][j] == maxValue[i][j] + triangle[i + 1][j])
					count[i + 1][j] += count[i][j];
				else {
					maxValue[i + 1][j] = max(maxValue[i][j] + triangle[i + 1][j], maxValue[i + 1][j]);
					
					count[i + 1][j] = (maxValue[i][j] + triangle[i + 1][j]) < maxValue[i + 1][j] ? count[i + 1][j] : count[i][j];
				}
				maxValue[i + 1][j + 1] = maxValue[i][j] + triangle[i + 1][j + 1];
				count[i + 1][j + 1] = count[i][j];
			}
		}

		int answer = 0;
		int v_max = 0;
		for (int i = 1; i <= N; i++)
		{
			if (maxValue[N][i] > v_max) {
				v_max = maxValue[N][i];
				answer = count[N][i];
			}
			else if (maxValue[N][i] == v_max) {
				answer += count[N][i];
			}
		}
		cout << answer << endl;
	}
}