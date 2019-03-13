	#include <stddef.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdlib.h>

	#define MAX_LENGTH 1000
	char *iterator;

	bool assertNotNull(char* input) {
		bool ret = true;

		if (input == NULL)
			ret = false;

		return ret;
	}

	char *reverse(char *input) {
		char head = *(input);
		char *ret = (char*)malloc(sizeof(char)*MAX_LENGTH);
		memset(ret, '\0', 1);

		if (head == 'w' || head == 'b') {
			char str[2] = { head , '\0' };
			memcpy(ret, str, 2);
		}

		else {
			char *leftTop = reverse(++iterator);
			char *rightTop = reverse(++iterator);
			char *leftBot = reverse(++iterator);
			char *rightBot = reverse(++iterator);

			char str[2] = { 'x','\0' };
			memcpy(ret + strlen(ret), str, 2);
			memcpy(ret + strlen(ret), leftBot, strlen(leftBot)+1);
			memcpy(ret + strlen(ret), rightBot, strlen(rightBot)+1);
			memcpy(ret + strlen(ret), leftTop, strlen(leftTop)+1);
			memcpy(ret + strlen(ret), rightTop, strlen(rightTop)+1);

			free(leftTop);
			free(leftBot);
			free(rightTop);
			free(rightBot);
		}

		return ret;
	}

	int main() {
		int caseNum;
		char *input = (char*)malloc(sizeof(char)*(MAX_LENGTH));
		char **ret = (char**)malloc(sizeof(char*)*MAX_LENGTH);

		scanf("%d", &caseNum);

		for (int i = 0; i < caseNum; i++) {
			scanf("%s", input);
			iterator = input;
			*(ret + i) = (char*)malloc(strlen(input) + 1);
			*(ret + i) = reverse(input);
		}

		for (int i = 0; i < caseNum; i++) {
			printf("%s\n", *(ret + i));
		}


		return 0;
	}