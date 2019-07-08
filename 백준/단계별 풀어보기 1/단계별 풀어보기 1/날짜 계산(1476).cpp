#include <stdio.h>

int main() {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int ret = (E*6916 + S*4845 + M*4200) % 7980;

	printf("%d\n", ret ? ret : 7980);

	return 0;
}