#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	char string[1000] = { 0 };
		scanf("%s", &string);
		scanf("%d", &a);
	printf("%c", string[a - 1]);
	return 0;
}