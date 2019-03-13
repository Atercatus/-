#include<iostream>
#include<algorithm>

using namespace std;

// ³»°¡ Ç¬ ¹æ½Ä
/*
const int INF = 1000000;
int cache[1000001];

int makeOne(int num) {
	int& ret = cache[num];

	if (num == 1)
		return ret = 0;

	if (ret != INF)
		return ret;

	if (num % 3 == 0)
		ret = min(ret, makeOne(num / 3) + 1);

	if (num % 2 == 0)
		ret = min(ret, makeOne(num / 2) + 1);

	if (num > 1)
		ret = min(ret, makeOne(num - 1) + 1);

	return ret;
}

*/

// 1µîÀÌ Ç¬ ¹æ½Ä
int makeOne(int num) {
	if (num < 2)
		return 0;

	int a = makeOne(num / 2) + num % 2 + 1;
	int b = makeOne(num / 3) + num % 3 + 1;

	return min(a, b);


}


int main() {
	int n;
	/*
	for (int i = 0; i < 1000001; i++) {
		cache[i] = INF;
	}
	*/

	cin >> n;
	int ret = makeOne(n);
	cout << ret << endl;

	return 0;
}