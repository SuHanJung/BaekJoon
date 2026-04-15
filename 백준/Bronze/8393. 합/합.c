#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	scanf("%d", &a);
	a = a * a + a;
		printf("%d", a / 2);

	return 0;
}