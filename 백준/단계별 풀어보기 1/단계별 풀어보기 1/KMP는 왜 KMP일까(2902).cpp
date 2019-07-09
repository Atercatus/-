#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int main() {
	char arr[MAX_SIZE] = {};

	scanf("%s", arr);

	printf("%c", arr[0]);
	for (int i = 1; i < strlen(arr); i++) {
		if (arr[i] == '-')
			printf("%c", arr[i + 1]);
	}

	return 0;
}