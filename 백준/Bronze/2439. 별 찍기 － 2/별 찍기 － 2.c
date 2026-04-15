#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0;
	scanf("%d", &a);
	
	for (int i = 1; i <= a; i++) {
		for (int p = 1; p <= a; p++) {
			b = p + i;
			if(b > a) {
				printf("*");
			}

			else{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}