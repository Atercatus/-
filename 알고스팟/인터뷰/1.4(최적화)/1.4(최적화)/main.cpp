#include<iostream>
#include<string>

using namespace std;

int toggle(int bitVector, int index) {
	if (index < 0) return bitVector;
	int mask = 1 << index;
	if ((bitVector & mask) == 0) {
		bitVector |= mask;
	}
	else {
		bitVector &= ~mask;
	}

	return bitVector;
}

int createBitVector(string phrase) {
	int bitVector = 0;
	for (int i = 0; i < phrase.size(); i++) {
		int c = phrase[i] - 'a';
		bitVector = toggle(bitVector, c);
	}
	
	return bitVector;
}


bool checkExactlyOneBitSet(int bitVector) {
	return (bitVector & (bitVector - 1)) == 0;
}

bool isPermutationOfPalindrome(string phrase) {
	int bitVector = createBitVector(phrase);
	return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}

int main() {
	string input;
	getline(cin, input);
	bool ret;
	ret = isPermutationOfPalindrome(input);
	if (ret) {
		cout << "True" << endl;
		return 0;
	}
	cout << "False" << endl;

	return 0;
}