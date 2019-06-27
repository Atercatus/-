#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

#define MAX_SIZE 100001
int cnt;

typedef struct {
	int age;
	char name[101];
	int cnt;
}Member;

bool compare(const Member *m1, const Member *m2) {
	if (m1->age == m2->age) {
		return m1->cnt < m2->cnt;
	}
	return m1->age < m2->age;
}

Member members[MAX_SIZE];
Member *membersPtr[MAX_SIZE];

int main() {
	cnt = 0;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < MAX_SIZE; i++) {
		membersPtr[i] = &members[i];
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &membersPtr[i]->age, membersPtr[i]->name);
		membersPtr[i]->cnt = cnt++;
	}

	std::sort(membersPtr, membersPtr + n, compare);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", membersPtr[i]->age, membersPtr[i]->name);
	}

	return 0;
}