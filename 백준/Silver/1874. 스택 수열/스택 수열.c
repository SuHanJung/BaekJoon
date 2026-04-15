#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0, input = 0, * arr, point = 0, len = 1;
	char ans[1000000] = { 0 };
	ans[0] = '+';
	scanf("%d", &n);
	arr = malloc(sizeof(int) * (n + 1));
	for (int t = 0; t <= n; t++)arr[t] = t;
	for (int t = 0; t < n; t++) {
		scanf("%d", &input);
		for (; point < input; point++) {
			if (arr[point] != 0) {
				ans[len] = '+';
				len++;
			}
		}
		if (point == input) {
			arr[point] = 0;
			for (; arr[point] == 0;) point--;
			ans[len] = '-';
			len++;
		}
		else {
			printf("NO");
			return 0;
		}
	}
	for (int t = 0; ans[t] != 0; t++) printf("%c\n", ans[t]);
	return 0;
}