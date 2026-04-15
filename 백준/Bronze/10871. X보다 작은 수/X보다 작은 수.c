#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b[10000] = { 0 }, c = 0, d = 0;
	scanf("%d %d", &a, &c);
		
		for (int i = 0; i < a; i++) {
			scanf("%d", &b[i]);
		}
	
		for (int i = 0; i < a; i++) {
			if (b[i] < c) {
				printf("%d\n", b[i]);
			}
		}

	return 0;
}