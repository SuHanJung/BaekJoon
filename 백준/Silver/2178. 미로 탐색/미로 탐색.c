#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0, M = 0, ans[105][105] = { 0 }, m = 0, n = 0, arr[10000] = { 0 };
	char input[105][105] = { 0 };
	arr[0] = 1001;
	ans[1][1] = 1;
	scanf("%d %d", &N, &M);
	for (int t = 1; t <= N;t++) scanf("%s", &input[t][1]);
	for (int t = 0, x = 0, y = 0;; t++) {
		if (ans[N][M] != 0) {
			printf("%d", ans[N][M]);
			break;
		}
		x = arr[t] / 1000;
		y = arr[t] % 1000;
		m++;
		if (input[x][y - 1] == '1' && ans[x][y - 1] == 0) {
			ans[x][y - 1] = ans[x][y] + 1;
			n++;
			arr[n] = x * 1000 + y - 1;
		}
		if (input[x][y + 1] == '1' && ans[x][y + 1] == 0) {
			ans[x][y + 1] = ans[x][y] + 1;
			n++;
			arr[n] = x * 1000 + y + 1;
		}
		if (input[x + 1][y] == '1' && ans[x + 1][y] == 0) {
			ans[x + 1][y] = ans[x][y] + 1;
			n++;
			arr[n] = (x + 1) * 1000 + y;
		}
		if (input[x - 1][y] == '1' && ans[x - 1][y] == 0) {
			ans[x - 1][y] = ans[x][y] + 1;
			n++;
			arr[n] = (x - 1) * 1000 + y;
		}
	}
	return 0;
}