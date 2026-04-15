#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0, c[101] = {0};
	scanf("%d %d", &a, &b);

	for (int i = 0; i < 101; i++) {
		c[i] = i;
	}
	

	for (int i = 0, p = 0, q = 0, r = 0; i < b; i++) {
		scanf("%d %d", &p, &q);
		r = c[p];
		c[p] = c[q];
		c[q] = r;
	}

	for (int i = 1; i <= a; i++) {
		printf( "%d ", c[i] );
	}
	return 0;
}