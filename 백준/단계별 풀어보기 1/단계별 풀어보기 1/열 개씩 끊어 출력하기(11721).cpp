#include <stdio.h>

int main() {
	char str[11];
	while (fgets(str, 11, stdin)) {
		printf("%s\n", str);
	}

	return 0;
}