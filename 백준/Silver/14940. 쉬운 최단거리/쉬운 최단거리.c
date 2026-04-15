#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int q[1000000] = { 0 }, in[1000][1000] = { 0 }, ans[1000][1000] = { 0 }, n = 0, m = 0, len = 0, left = 0;
	scanf("%d %d", &m, &n);
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			scanf("%d", &in[x][y]);
			if (in[x][y] == 1) left++;
			else if (in[x][y] == 2) q[0] = x * 10000 + y;
		}
	}
	for (int t = 0, x = 0, y = 0;t <= len + 1;t++) {
		x = q[t] / 10000;
		y = q[t] % 10000;
		if (x > 0 && in[x - 1][y] == 1 && ans[x - 1][y] == 0) {
			ans[x - 1][y] = ans[x][y] + 1;
			len++;
			q[len] = (x - 1) * 10000 + y;
			left--;
		}
		if (x < m && in[x + 1][y] == 1 && ans[x + 1][y] == 0) {
			ans[x + 1][y] = ans[x][y] + 1;
			len++;
			q[len] = (x + 1) * 10000 + y;
			left--;
		}
		if (y > 0 && in[x][y - 1] == 1 && ans[x][y - 1] == 0) {
			ans[x][y - 1] = ans[x][y] + 1;
			len++;
			q[len] = x * 10000 + y - 1;
			left--;
		}
		if (y < n && in[x][y + 1] == 1 && ans[x][y + 1] == 0) {
			ans[x][y + 1] = ans[x][y] + 1;
			len++;
			q[len] = x * 10000 + y + 1;
			left--;
		}
	}
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (ans[x][y] == 0 && in[x][y] == 1) printf("-1 ");
			else printf("%d ", ans[x][y]);
		}
		printf("\n");
	}
	return 0;
}