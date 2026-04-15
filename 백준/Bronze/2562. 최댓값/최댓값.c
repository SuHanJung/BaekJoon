#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0;
	for (int i = 1, p = 0; i < 10; i++) {
		scanf("%d", &p);
		if (p > b) {
			b = p;
			a = i;
		}
	}
	printf("%d\n%d", b, a);
	return 0;
}