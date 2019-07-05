#pragma warning(disable:4996)
#include <stdio.h>

#define MAX_SIZE 101

int main() {
	char a;

	while(scanf("%c", &a) != EOF)
		printf("%c", a);

	return 0;
}