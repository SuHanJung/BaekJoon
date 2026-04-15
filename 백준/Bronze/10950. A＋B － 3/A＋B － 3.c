#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0, c = 0;
	scanf("%d", &c);
	
	for (int i = 0; i < c; i++) {
		scanf("%d %d", &a, &b);
		printf("%d \n", a + b);
	}

	return 0;
}