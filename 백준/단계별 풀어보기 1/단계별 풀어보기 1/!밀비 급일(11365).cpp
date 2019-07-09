#include <stdio.h>
#include <string.h>

#define MAX_SIZE 501

int main() {
	char arr[MAX_SIZE];

	while (1) {
		scanf(" %[^\n]", arr);
		if (strcmp(arr, "END") == 0) {
			break;
		}
		for (int i = strlen(arr) - 1; i >= 0; i--) {
			printf("%c", arr[i]);
		}
		printf("\n");
	}

	return 0;
}/*
int main() {
	char arr[MAX_SIZE];

	while (1) {
		fgets(arr, MAX_SIZE, stdin);
		if (strcmp(arr, "END\n") == 0) {
			break;
		}
		for (int i = strlen(arr) - 2; i >= 0; i--) {
			printf("%c", arr[i]);
		}
		printf("\n");
	}

	return 0;
}*/