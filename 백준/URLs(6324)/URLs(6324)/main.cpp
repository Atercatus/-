#pragma warning(disable:4996)
#include <stdio.h>

#define PROTOCOL_SIZE 7
#define MAX_SIZE 61
#define PORT_SIZE 10

void append(char* dst, char c) {
	char *p = dst;
	while (*p != '\0')
		p++;
	*p = c;
	*(p + 1) = '\0';
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char protocol[PROTOCOL_SIZE] = {};
		char host[MAX_SIZE] = {};
		char port[PORT_SIZE] = "<default>";
		char path[MAX_SIZE]= "<default>";
		char url[MAX_SIZE] = {};
		scanf("%s", url);

		char *cur = url;

		// protocol
		while (*cur != ':') {
			append(protocol, *cur++);
		}
		cur += 3; // ://

		// host
		while (*cur != '/' && *cur != ':' && *cur != '\0') {
			append(host, *cur++);
		}

		// port
		if (*cur == ':') {
			cur++;
			port[0] = '\0';
			while (*cur != '/' && *cur != '\0') {
				append(port, *cur++);
			}
		}
		if(*cur == '/')
			cur++;

		// path
		if (*cur != '\0') {
			path[0] = '\0';
			while (*cur != '\0') {
				append(path, *cur++);
			}
		}

		printf("URL #%d\n", i + 1);
		printf("Protocol = %s\n", protocol);
		printf("Host     = %s\n", host);
		printf("Port     = %s\n", port);
		printf("Path     = %s\n", path);
		printf("\n");
	}

	return 0;
}