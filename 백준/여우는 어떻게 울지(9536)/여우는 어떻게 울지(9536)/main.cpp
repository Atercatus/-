#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10101
#define MAX_ANIMALS 101
#define MAX_WORDS 101
	
char bleats[MAX_ANIMALS][MAX_WORDS];
int totalTypes;

bool compare(char* sample) {
	for (int i = 0; i < totalTypes; i++) {
		if (
			strcmp(sample, bleats[i]) == 0)
			return true;
	}
	return false;
}

void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0') 
		p++;
	*p = c;
	*(p + 1) = '\0';
}

void sampling(char* audio) {
	char tmp[MAX_WORDS] = "\0";
	char *cur = audio;
	while (*cur != '\0') {
		if (*cur == ' ') {
			if (!compare(tmp)) {
				printf("%s ", tmp);
			}
			tmp[0] = 0;
		}
		else {
			append(tmp, *cur);
		}
		cur++;
	}
	if (!compare(tmp)) {
		printf("%s\n", tmp);
	}
}

void clear_stdin() {
	int ch;
	while ((ch = getchar()) != EOF || ch != '\n') {};
}

int main() {
	int c = 0;
	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		while (getchar() != '\n') {} // \n Á¦°Å
		totalTypes = 0;
		char audio[MAX_SIZE] = {};
		fgets(audio, MAX_SIZE, stdin);
		audio[strlen(audio) - 1] = 0;

		char buf[MAX_SIZE] = {};
		
		while (1) {
			scanf("%s %s", buf, buf);

			if (strcmp(buf, "goes") != 0)
				break;

			scanf("%s", bleats[totalTypes++]);
		}

		scanf("%s %s %s", buf, buf, buf);
		sampling(audio);
	}

	return 0;
}