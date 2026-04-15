#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	scanf("%d", &a);
	a /= 4;
	
	for (int i = 0; i < a; i++) {
		printf("long ");
	}

	printf("int");

	return 0;
}