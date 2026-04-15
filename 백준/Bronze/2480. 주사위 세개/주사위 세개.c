#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 0, b = 0, c = 0;
	int arr[7] = { 0 };
	scanf("%d %d %d", &a, &b, &c);
	arr[a]++;
	arr[b]++;
	arr[c]++;

	for (int i = 0; i <= 6; i++) {
		if (arr[i] == 3) {
			printf("%d", 1000 * i + 10000);
				return 0;
		}
	}
	
	for (int i = 0; i <= 6; i++) {
		if (arr[i] == 2) {
			printf("%d", 100 * i + 1000);
				return 0;
		}
	}

	for (int i = 0; i <= 6; i++) {
		if (arr[6 - i] == 1) {
			printf("%d", (6 - i) * 100);
				return 0;
		}
	}

	return 0;
}