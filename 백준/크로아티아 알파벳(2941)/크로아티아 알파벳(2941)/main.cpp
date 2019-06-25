#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101
#define MAX_CALPHABET 8

char CAlphabet[MAX_CALPHABET][4] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
int len;

int compare(char* input) {
	for (int i = 0; i < MAX_CALPHABET; i++) {
		int idx = 0;
		bool ret = true;
		for (idx = 0; ret && (CAlphabet[i][idx] != '\0'); idx++) {
			if (*(input + idx) != CAlphabet[i][idx])
				ret = false;
		}

		if (ret)
			return idx-1;
	}
	return 0;
}

int check(char* input) {
	int ret = 0;
	for (int i = 0; i < len; i++) {
		ret++;
		i += compare(input + i);
	}

	return ret;
}

int main() {
	char input[MAX_SIZE] = {};
	scanf("%s", input);
	len = strlen(input);
	printf("%d\n", check(input));

	return 0;
}