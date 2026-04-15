#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	float a = 0, b = 0, c = 0, d = 0;
	scanf("%f", &a);
	for (float i = 0, k = 0; i < a; i++) {
		scanf("%f", &k);
		b = b + k;
		if (k > d) d = k;
	}

	c = b / a;
	c = c * 100 / d;
	printf("%f", c);
	return 0;
}