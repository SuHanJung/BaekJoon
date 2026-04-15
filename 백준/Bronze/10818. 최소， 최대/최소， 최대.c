#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = -1000000, c = 1000000;
	scanf("%d", &a);
		
		for (int i = 0, p = 0; i < a; i++) {
			scanf("%d", &p);

			if (p > b) {
				b = p;
			}

			if (p < c) {
				c = p;
			}
		}
		printf("%d %d", c, b);
	return 0;
}