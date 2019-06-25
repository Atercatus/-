#pragma warning(disable:4996)
#include <stdio.h>

#define MAX_SIZE 10001

char* cur;

bool isDigit(char target) {
	return ('0' < target && target <= '9');
}

int getAtomicWeight(char atomic) {
	int ret = 0;
	// C - 12
	switch (atomic) {
	case 'C':
		ret = 12;
		break;
		// H - 1
	case 'H':
		ret = 1;
		break;
		// O = 16
	case 'O':
		ret = 16;
		break;
	}

	return ret;
}

int calc() {
	int ret = 0;
	int weight = 0;

	while (*cur != '\0' && *cur != ')') {
		int multi = 1;

		if (*cur == '(') {
			ret += weight;
			cur++;
			weight = calc();
			continue;
		}

		if (isDigit(*cur)) {
			multi = *cur - '0';
			weight = weight * multi;
			ret += weight;
			weight = 0;
		}
		else {
			ret += weight;
			weight = getAtomicWeight(*cur);
		}

		cur++;
	}

	cur++;
	ret += weight;
	return ret;
}


int main() {
	char input[MAX_SIZE];
	scanf("%s", input);
	cur = input;

	int ret = calc();
	printf("%d\n", ret);

	return 0;
}