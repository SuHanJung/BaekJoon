#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 0, b = 0, c = 0;
	scanf("%d %d", &a, &b);
	c = a * 60 + b - 45;
	
	if (c < 0) {
		c = c + 1440;
	}

	a = c / 60;
	b = c % 60;
	printf("%d %d", a, b);
	return 0;
}