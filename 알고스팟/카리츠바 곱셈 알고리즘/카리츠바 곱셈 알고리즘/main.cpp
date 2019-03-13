#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// ÀÚ¸´¼ö ¿Ã¸²
void normalize(vector<int>& num) {
	num.push_back(0);

	for (int i = 0; i < num.size() - 1; i++) {
		if (num[i] < 0) {
			int borrow = abs(num[i]) + 9 / 10; // -1 ºÎÅÍ ÀÌ±â ¶§¹®¿¡ +9
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}

	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

// ±âº» °ö¼À
vector<int> multiply(const vector<int>& op1, const vector<int>& op2) {
	vector<int> ret(op1.size() + op2.size() + 1, 0);

	for (int i = 0; i < op1.size(); i++)
		for (int j = 0; j < op2.size(); j++)
			ret[i + j] += op1[i] * op2[j];
	
	normalize(ret);

	return ret;
}

// µ¡¼À op1 += (op2)*10^k  // Ä«¸®Ã÷¹Ù °ö¼ÀÀ§ÇØ¼­ ¹ÝÀ¸·Î ³ª´« ºÎºÐÀ» ÇÕÄ¥ ¶§ »ç¿ëÇÏ¹Ç·Î ÀÌ·±½ÄÀ¸·Î ±¸ÇöÇÔ
void addTo(vector<int>& op1, vector<int>& op2, int k) {
	int maxSize = op1.size() > (op2.size()+ k) ? op1.size() : (op2.size()+k);
	op1.resize(maxSize);

	for (int i = 0; i < op2.size(); i++) {
		op1[k + i] += op2[i];
	}

	normalize(op1);
}

// ±âº» »¬¼À op1 -= op2 // op1 > op2 °¡Á¤
void subFrom(vector<int>& op1, vector<int>& op2) {

	for (int i = 0; i < op2.size(); i++) {
		op1[i] -= op2[i];
	}

	normalize(op1);
}

vector<int> karitsuba(vector<int>&op1, vector<int>&op2) {
	int size1 = op1.size();
	int size2 = op2.size();
	
	if (size1 < size2)
		return karitsuba(op2, op1);
	
	if (size1 == 0 || size2 == 0)
		return vector<int>();

	if (size1 <= 50)
		return multiply(op1, op2);

	int half = size1 / 2;

	vector<int> a0(op1.begin(), op1.begin() + half);
	vector<int> a1(op1.begin() + half, op1.end());
	vector<int> b0(op2.begin(), op2.begin() + min<int>(half, op2.size()));
	vector<int> b1(op2.begin() + min<int>(half, op2.size()), op2.end());

	vector<int> z0 = karitsuba(a0, b0);
	vector<int> z2 = karitsuba(a1, b1);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karitsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, size1);

	return ret;
}

int main() {
	string input1, input2;
	vector<int> op1, op2;
	vector<int> ret;

	cin >> input1 >> input2;

	int val;
	char c;
	for (int i = input1.size()-1; i >= 0; i--) {
		val = input1[i]-48;
		op1.push_back(val);
	}
	for (int i = input2.size()-1; i >= 0; i--) {
		val = input2[i]-48;
		op2.push_back(val);
	}
	
	ret = karitsuba(op1, op2);
	//addTo(op1, op2, 0);
	//ret = op1;

	for (int i = ret.size()-1; i >= 0; i--) {
		cout << ret[i];
	}
	cout << endl;

	return 0;
}