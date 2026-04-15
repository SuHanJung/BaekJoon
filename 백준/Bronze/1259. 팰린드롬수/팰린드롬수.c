#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0, b = 0, c = 0;
	scanf("%d", &a);
	for (; a != 0; scanf("%d", &a)) {
		b = 0;
		c = a;
		for (int time = 0, k = 10000; time < 5; time++) {
			b += k * (a % 10);
			k /= 10;
			a /= 10;
		}
		for (; b % 10 == 0; b /= 10);
		if (c == b) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}