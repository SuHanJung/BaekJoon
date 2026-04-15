#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 0, b = 0;
	scanf("%d", &a);
	b = a % 100;
	
	if (b == 0) {
		if (a % 400 == 0) {
			printf("1");
		}
		else printf("0");
	}

	else {
		if (b % 4 == 0) {
			printf("1");
		}
		else printf("0");
	}
		
	return 0;
}