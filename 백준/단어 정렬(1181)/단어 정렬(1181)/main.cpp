#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX_SIZE 20000


bool compare(char* arr1, char* arr2) {
	if (strlen(arr1) == strlen(arr2)) {
		return strcmp(arr1, arr2) < 0;
	}

	return strlen(arr1) < strlen(arr2);
}



int main() {
	int n;
	char* arr[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		arr[i] = (char*)malloc(51);
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	std::sort(arr, arr + n, compare);

	char tmp[51] = {};
	for (int i = 0; i < n; i++) {
		if (strcmp(arr[i],tmp) == 0)
			continue;
		strcpy(tmp, arr[i]);
		printf("%s\n", arr[i]);
	}

	return 0;

 }