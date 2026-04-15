#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int x = 0, y = 0, left = 0, arr[1100000][2] = { 0 }, arrst = 0, arrend = 0, input[1005][1005] = { 0 };
	scanf("%d %d", &x, &y);
	for (int t = 0; t < x + 2; t++) {
		input[t][0] = -1;
		input[t][y + 1] = -1;
	}
	for (int t = 0; t < y + 2; t++) {
		input[0][t] = -1;
		input[x + 1][t] = -1;
	}
	for (int t = 1; t <= y; t++) {
		for (int tt = 1; tt <= x; tt++) {
			scanf("%d", &input[tt][t]);
			if (input[tt][t] == 0) left++;
			else if (input[tt][t] == 1) {
				arr[arrend][0] = 10000 * tt + t;
				arr[arrend][1] = 1;
				arrend++;
			}
		}
	}
	if (left == 0) {
		printf("0");
		return 0;
	}
	for (int ch = left, instx = 0, insty = 0;left != 0 && arr[arrst][0] != 0;) {
		instx = arr[arrst][0] / 10000;
		insty = arr[arrst][0] % 10000;
		arrst++;
		if (input[instx + 1][insty] == 0) {
			input[instx + 1][insty] = 1;
			arr[arrend][0] = (instx + 1) * 10000 + insty;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx - 1][insty] == 0) {
			input[instx - 1][insty] = 1;
			arr[arrend][0] = (instx - 1) * 10000 + insty;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx][insty + 1] == 0) {
			input[instx][insty + 1] = 1;
			arr[arrend][0] = instx * 10000 + insty + 1;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
		if (input[instx][insty - 1] == 0) {
			input[instx][insty - 1] = 1;
			arr[arrend][0] = instx * 10000 + insty - 1;
			arr[arrend][1] = arr[arrst - 1][1] + 1;
			left--;
			arrend++;
		}
	}
	if (left == 0) printf("%d", arr[arrst - 1][1]);
	else printf("-1");
	return 0;
}