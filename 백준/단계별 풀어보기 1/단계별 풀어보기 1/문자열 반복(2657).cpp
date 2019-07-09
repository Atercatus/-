#include <stdio.h>
#include <string.h>

#define MAX_SIZE 21

int main() {
	int c;
	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		int n;
		char arr[MAX_SIZE] = {};
		scanf("%d %s", &n, arr);

		for (int j = 0; j < strlen(arr) ; j++) {
			for (int k = 0; k < n; k++)
				printf("%c", arr[j]);
 		}

		printf("\n");
	}

	return 0;
}