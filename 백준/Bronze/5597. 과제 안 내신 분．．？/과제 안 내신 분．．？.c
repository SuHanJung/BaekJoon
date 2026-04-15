#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0, c[31] = {0};

	for (int i = 0; i < 28; i++) {
		scanf("%d", &a);
		c[a] = 1;
	}

	for (int i = 1, t = 0; i < 31; i++) {
		if (c[i] == 0) {
			if (t == 0) {
				printf("%d\n", i);
			}
			else
			{
				printf("%d", i);
				break;
			}
		}

	}

	return 0;
}