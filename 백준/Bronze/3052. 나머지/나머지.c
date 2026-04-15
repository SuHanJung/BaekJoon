#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0, c[43] = {0};

	for (int i = 0; i < 10; i++) {
		scanf("%d", &a);
		a = a % 42;
		c[a]++;
	}

	for (int i = 0; i < 43;i++) {
		if (c[i] != 0) {
			b++;
		}
	}

	printf("%d", b);

	return 0;
}