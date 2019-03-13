#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


vector<int> P;
vector<int> Q;
int pairs = 0;
int minDis = 100000001;
//int MIN = 100000001;
int n, m, c1, c2;
int tip = 0;

void findClosestPair() {
	for (int i = 0; i < P.size(); i++) {
		tip = 0;
		for (int j = 0; j < Q.size(); j++) {
			int tmp = abs(P[i] - Q[j]);

			if (tmp == minDis) {
				pairs++;
				if (tip == 2)
					break;
			}

			else if (tmp < minDis) {
				//MIN = tmp;
				pairs = 1;
				minDis = tmp;
				tip += 1;
			}
		}
	}
}


int main() {
	int p, q;

	cin >> n >> m;
	cin >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin >> p;
		P.push_back(p);
	}
	sort(P.begin(), P.end());

	

	for (int i = 0; i < m; i++) {
		cin >> q;
		Q.push_back(q);
	}
	sort(Q.begin(), Q.end());
	/*
	for (int i = 0; i < P.size(); i++)
		cout << P[i] << endl;
	for (int i = 0; i < Q.size(); i++)
		cout << Q[i] << endl;
	*/

	findClosestPair();

	int ret = minDis + abs(c1 - c2);

	cout << ret << " " << pairs << endl;

	return 0;
}