#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0, c[101] = { 0 }, d[101] = { 0 };

	scanf("%d %d", &a, &b);

	for (int i = 1; i <= a; i++) {
		c[i] = i;
	}

	for (int i = 0, min = 0, max = 0; i < b; i++) {
		scanf("%d %d", &min, &max);
		for (int t = 0,p = min, q = max; p <= q; p++) {
			d[q - t] = c[p];
			t++;
		}
		for (int p = min, q = max; p <= q; p++) {
			c[p] = d[p];
		}
	}

	for (int i = 1; i < a; i++) {
		printf("%d ", c[i]);
	}
	printf("%d", c[a]);

	return 0;
}