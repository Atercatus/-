#pragma warning(disable:4996)

#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX_SIZE 100001

typedef struct {
	char name[11];
	int korean;
	int english;
	int math;
}Student;

bool compare(Student* s1, Student* s2) {
	if(s1->korean != s2->korean)
		return s1->korean > s2->korean;

	if(s1->english != s2->english)
		return s1->english < s2->english;

	if(s1->math == s2->math)
		return strcmp(s1->name, s2->name) < 0;

	return s1->math > s2->math;
}

Student arr[MAX_SIZE];
Student* arrPtr[MAX_SIZE];

int main() {
	int c;
	scanf("%d ", &c);

	for (int j = 0; j < MAX_SIZE; j++) {
		arrPtr[j] = &arr[j];
	}

	for (int i = 0; i < c; i++) {
		scanf("%s %d %d %d", arr[i].name, &arr[i].korean, &arr[i].english, &arr[i].math);
	}

	sort(arrPtr, arrPtr + c, compare);

	for (int i = 0; i < c; i++) {
		printf("%s\n", arrPtr[i]->name);
	}

	return 0;
}