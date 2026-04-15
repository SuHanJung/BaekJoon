#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0, c[101] = {0};
	scanf("%d %d", &a, &b);

	for (int i = 0, p = 0, q = 0, r = 0; i < b; i++) {
		scanf("%d %d %d", &p, &q, &r);
		for (int t = p; t <= q; t++) {
			c[t] = r;
		}
	}

	for (int i = 1; i <= a; i++) {
		printf( "%d ", c[i] );
	}
	return 0;
}