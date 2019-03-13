#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//int main() {
//	FILE * fp1 = fopen("dst3.bin", "wb");
//	FILE * fp2 = fopen("dst3.bin", "rb");
//	char c[] = "this is tutorial";
//	char buffer[100];
//
//	fwrite((void*)c, 1, strlen(c) + 1, fp1);
//	fclose(fp1);
//
//	int n = fread((void*)buffer, 1, strlen(c) + 1, fp2);
//
//	printf("%s\n", buffer);
//	printf("%d\n", n);
//	fclose(fp2);
//
//	return 0;
//}

int main() {
	char name[10];
	char sex;
	int age;

	FILE *fp = fopen("friend.txt", "wt");

	for (int i = 0; i < 3; i++) {
		scanf("%s %c %d", name, &sex, &age);
		getchar();
		fprintf(fp, "%s %c %d \n", name, sex, age);
	}
	fclose(fp);

	return 0;
}