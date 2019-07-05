#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int ret = 0;
	char c;

	while(scanf("%c", &c) != EOF) {
		if('0' <= c && c <= '9')
			ret += c - '0';
	}
	printf("%d\n", ret);

	return 0;
}