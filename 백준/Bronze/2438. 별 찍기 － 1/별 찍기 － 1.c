#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	scanf("%d", &a);
	
	for (int i = 1; i <= a; i++) {
		for (int p = 0; p < i; p++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}