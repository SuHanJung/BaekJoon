#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	char arr[11] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A' };
	scanf("%d", &a);
	a /= 10;
	printf("%c", arr[a]);
	return 0;
}