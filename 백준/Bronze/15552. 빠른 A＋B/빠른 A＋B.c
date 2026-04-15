#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0, c = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d %d", &b, &c);
		printf("%d\n", b + c);
	}

	return 0;
}