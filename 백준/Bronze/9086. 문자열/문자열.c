#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0;
	char string[1001] = { 0 };
	scanf("%d", &a);
	for (int i = 0; i < a;i++) {
		scanf("%s", &string);
		for (int i = 0; string[i] != 0; i++) {
			b = i;
		}
		printf("%c%c\n", string[0], string[b]);
		}
	return 0;
}