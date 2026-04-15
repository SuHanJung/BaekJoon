#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	
	for (;;) {
		if (scanf("%d %d", &a, &b) == EOF) {
			break;
		}
		else printf("%d\n", a + b);
	}
	return 0;
}