#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//int main() {
//	FILE *fp1 = fopen("dst2.bin", "wb");
//	FILE *fp2 = fopen("dst2.bin", "rb");
//	char c[] = "this is tutorialspoint";
//	char buffer[100];
//
//	/* Write data to the file */
//	fwrite((void*)c, 1, strlen(c) + 1, fp1);
//
//	/* Seek to the beginning of the file */
//	fseek(fp1, 0, SEEK_SET);
//
//	/* Read and display data */
//	int n = fread((void*)buffer, 1, strlen(c) + 1, fp2);
//	printf("%d\n", n);
//	printf("%s\n", buffer);
//	fclose(fp1);
//	fclose(fp2);
//
//	return(0);
//}


int main()
{
	char str[80];
	float f;
	FILE * pFile;

	pFile = fopen("myfile.txt", "w+");
	fprintf(pFile, "%f %s", 3.1416, "PI");
	rewind(pFile);
	fscanf(pFile, "%f", &f);
	fscanf(pFile, "%s", str);
	fclose(pFile);
	printf("I have read: %f and %s \n", f, str);
	return 0;
}