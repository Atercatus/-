#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N = 7;

	long long answer = 0;

	for (int i = 2; i <= N; i++) {
		bool isPrime = true;
		int max = round(sqrt(i));
		for (int j = 2; j <= max; j++) {
			if (i%j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			answer += i;
	}

	cout << answer << endl;

	return 0;
}