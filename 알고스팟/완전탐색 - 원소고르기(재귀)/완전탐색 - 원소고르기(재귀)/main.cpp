#include <vector>
using namespace std;

void printPicked(vector<int>& picked) {
	for (int i = 0; i < picked.size(); i++)
	{
		printf("%d ", picked[i]);
	}
	printf("\n");
}

void pick(int n, vector<int>& picked, int toPick) {
	// ±âÀú»ç·Ê!~!
	if (toPick == 0) { 
		printPicked(picked);
		return; 
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int i = smallest; i < n; i++) {
		picked.push_back(i);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	int _n, _toPick;
	vector<int> picked;
	scanf_s("%d %d", &_n, &_toPick);

	pick(_n, picked, _toPick);

	system("pause");
	return 0;
}

