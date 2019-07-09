#include <stdio.h>
#include <string.h>

int main() {
	int alphabet[26] = {};
	for (int i = 0; i < 26; i++) {
		alphabet[i] = -1;
	}

	char input[101];
	scanf("%s", input);

	for (int i = 0; i < strlen(input); i++) {
		if (alphabet[input[i] - 'a'] == -1)
			alphabet[input[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}

	return 0;
}