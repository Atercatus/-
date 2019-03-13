#include <iostream>

using namespace std;

int dp[100001][3];

int main() {
	int penSize; 
	cin >> penSize;

	dp[1][0] = dp[1][1] = dp[1][2] = 1;

	// 0: nothing
	// 1: left
	// 2: right
	for (int i = 2; i <= penSize; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	int ret = dp[penSize][0] + dp[penSize][1] + dp[penSize][2];
	ret %= 9901;
	cout << ret << endl;

	return 0;
}










//char cage[100001][2]; // 0, 1
//int buffer[100001][2]; // 
//int cageSize;
//
//
//int allocate(int pos) {
//	if (pos > cageSize) {
//		return 1;
//	}
//
//	int ret = 0;
//
//	 �ƹ��͵� ���� �ʴ� ���
//	ret += allocate(pos + 1);
//
//	 ���ʿ� �δ� ���
//	if (cage[pos - 1][0] == 0) {
//		if (buffer[pos][0] != -1) {
//			ret += buffer[pos][0];
//		}
//		else {
//			cage[pos][0] = 1;
//			buffer[pos][0] = allocate(pos + 1);
//			ret += buffer[pos][0];
//			cage[pos][0] = 0;
//		}
//	}
//
//	 �����ʿ� �δ� ���
//	if (cage[pos - 1][1] == 0) {
//		if (buffer[pos][1] != -1) {
//			ret += buffer[pos][1];
//		}
//		else {
//			cage[pos][1] = 1;
//			buffer[pos][1] = allocate(pos + 1);
//			ret += buffer[pos][1];
//			cage[pos][1] = 0;
//		}
//	}
//
//	return ret;
//}
//
// ù° �ٿ� �츮�� ũ�� N(1��N��100,000)�� �־�����.
// ù° �ٿ� ���ڸ� ��ġ�ϴ� ����� ���� 9901�� ���� �������� ����Ͽ���.
//int main() {
//	 initialize
//	for (int i = 0; i < 100001; i++) {
//		cage[i][0] = 0;
//		cage[i][1] = 0;
//		buffer[i][0] = -1;
//		buffer[i][1] = -1;
//	}
//
//	cin >> cageSize;
//
//	int ret = allocate(1);
//	ret %= 9901;
//
//	cout << ret << endl;
//
//	return 0;
//}