#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// basic multiply
vector<int> multiply(const vector<int> &opnd1, const vector<int> &opnd2) {
	vector<int>ret(opnd1.size() + opnd2.size(), 0);

	for (int i = 0; i < opnd1.size(); i++) {
		for (int j = 0; j < opnd2.size(); j++) {
			ret[i + j] += opnd1[i] * opnd2[j];
		}
	}

	return ret;
}

//opnd1 = opnd1 + opnd2*10^k
void addTo(vector<int> &opnd1, const vector<int> &opnd2, int k) {
	opnd1.resize(max(opnd1.size(), opnd2.size() + k));

	for (int i = 0; i < opnd2.size(); i++) {
		opnd1[i + k] += opnd2[i];
	}

}

// opnd1 = opnd1 - opnd2
// opnd1 > opnd2
void subFrom(vector<int> &opnd1, const vector<int> &opnd2) {
	
	for (int i = 0; i < opnd2.size(); i++) {
		opnd1[i] -= opnd2[i];
	}
}


vector<int> karatsuba(const vector<int> &opnd1, const vector<int> &opnd2) {
	int size_op1 = opnd1.size();
	int size_op2 = opnd2.size();

	if (size_op1 < size_op2) // ³ªÁß¿¡ »¬¼ÀÀ» À§ÇØ¼­
		return karatsuba(opnd2, opnd1);

	if (size_op1 == 0 || size_op2 == 0)
		return vector<int>();

	if (size_op1 <= 50)
		return multiply(opnd1, opnd2);

	int half = size_op1 / 2;

	vector<int> a0(opnd1.begin(), opnd1.begin() + half);
	vector<int> a1(opnd1.begin() + half, opnd1.end()); // 10^k
	vector<int> b0(opnd2.begin(), opnd2.begin() + min<int>(half, opnd2.size()));
	vector<int> b1(opnd2.begin() + min<int>(half, opnd2.size()), opnd2.end()); // 10^k

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;
}

int countHugs(vector<int>& ret, int numIdols, int numFans) {
	int cnt = 0;

	for (int i = numIdols - 1; i < numFans; i++) {
		if (ret[i] == 0)
			cnt++;
	}

	return cnt;
}

int main() {
	int n; // #case
	cin >> n;
	vector<int> numHugs;

	for (int k = 0; k < n; k++) {
		string idolsStr, fansStr;
		vector<int> idols, fans;
		vector<int> ret;

		cin >> idolsStr >> fansStr;

		int val = 0;
		for (int i = 0; i < idolsStr.size(); i++) {
			val = (idolsStr[i] == 'M') ? 1 : 0;
			idols.push_back(val);
		}
		for (int i = fansStr.size() - 1; i >= 0; i--) {
			val = (fansStr[i] == 'M') ? 1 : 0;
			fans.push_back(val);
		}
		/*for (int i = 0; i < idols.size(); i++) {
		cout << idols[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < fans.size(); i++) {
		cout << fans[i] << " ";
		}*/
		//cout << endl;
		ret = karatsuba(idols, fans);
		/*for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
		cout << endl;*/
		numHugs.push_back(countHugs(ret, idols.size(), fans.size()));
	}

	for (int i = 0; i < numHugs.size(); i++) {
		cout << numHugs[i] << endl;
	}

	return 0;
}