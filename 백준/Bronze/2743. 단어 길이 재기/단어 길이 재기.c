#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	char string[1001] = { 0 };
	scanf("%s", &string);
	for (int i = 0; a == 0;i++) {
		if ((string[i]) == 0) {
			a = i;
			break;
		}
	}
	printf("%d", a);
	return 0;
}	