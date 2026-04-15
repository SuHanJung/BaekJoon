#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 0, b = 0, c = 0, d = 0;
	scanf("%d %d %d", &a, &b, &d);
	c = a * 60 + b + d;
	
	if (c >= 1440) {
		c = c - 1440;
	}

	a = c / 60;
	b = c % 60;
	printf("%d %d", a, b);
	return 0;
}