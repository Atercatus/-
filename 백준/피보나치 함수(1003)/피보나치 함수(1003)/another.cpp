//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int cache[41];
//
//void fibonacci(int n) {
//	cache[0] = 0;
//	cache[1] = 1;
//
//	for (int i = 2; i <= n; i++) {
//		cache[i] = cache[i - 1] + cache[i - 2];
//	}
//}
//
//int main() {
//	int case_num;
//	int input;
//	cin >> case_num;
//
//	vector<int> ret;
//
//	for (int i = 0; i < case_num; i++) {
//		cin >> input;
//
//		fibonacci(input);
//
//		if (input == 0)
//			cout << "1 0" << endl;
//		else {
//			cout << cache[input - 1] << " " << cache[input] << endl;
//		}
//	}
//
//	return 0;
//}