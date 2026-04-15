#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int start = 2, n = 2, input = 0;
	scanf("%d", &input);
	if (input == 1) {
		printf("1");
		return 0;
	}
	for (;input > 2;) {
		if (input % 2 == 0) start += n;
		n *= 2;
		input = input - (input / 2);
	}
	printf("%d", start);
	return 0;
}