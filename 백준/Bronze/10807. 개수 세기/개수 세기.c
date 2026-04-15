#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b[100] = { 0 }, c = 0, d = 0;
	scanf("%d", &a);
		
		for (int i = 0; i < a; i++) {
			scanf("%d", &b[i]);
		}

		scanf("%d", &c);
	
		for (int i = 0; i < a; i++) {
			if (b[i] == c) d++;
		}

		printf("%d", d);

	return 0;
}