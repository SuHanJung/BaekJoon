#include <stdio.h>
#include <malloc.h>
int main() {
	int width = 0, height = 0, q[1000000] = { 0 }, ans = 0;
	char campus[606][606] = { 0 };
	scanf("%d%d", &height, &width);
	for (int t = 0; t <= height + 1; t++) {
		campus[t][0] = 'X';
		campus[t][width + 1] = 'X';
	}
	for (int t = 0; t <= width + 1; t++) {
		campus[0][t] = 'X';
		campus[height + 1][t] = 'X';
	}
	for (int t = 1; t <= height; t++) {
		while (getchar() != '\n');
		for (int tt = 1; tt <= width; tt++) {
			scanf("%c", &campus[t][tt]);
			if (campus[t][tt] == 'I') {
				q[++q[0]] = t * 1000 + tt;
				campus[t][tt] = 'X';
			}
		}
	}
	for (int t = 1, y = 0, x = 0; t <= q[0]; t++) {
		x = q[t] % 1000;
		y = q[t] / 1000;
		if (campus[y + 1][x] == 'X');
		else {
			if (campus[y + 1][x] == 'P') ans++;
			campus[y + 1][x] = 'X';
			q[++q[0]] = (y + 1) * 1000 + x;
		}
		if (campus[y - 1][x] == 'X');
		else {
			if (campus[y - 1][x] == 'P') ans++;
			campus[y - 1][x] = 'X';
			q[++q[0]] = (y - 1) * 1000 + x;
		}
		if (campus[y][x + 1] == 'X');
		else {
			if (campus[y][x + 1] == 'P') ans++;
			campus[y][x + 1] = 'X';
			q[++q[0]] = y * 1000 + x + 1;
		}
		if (campus[y][x - 1] == 'X');
		else {
			if (campus[y][x - 1] == 'P') ans++;
			campus[y][x - 1] = 'X';
			q[++q[0]] = y * 1000 + x - 1;
		}
	}
	if (ans == 0) printf("TT");
	else printf("%d", ans);
	return 0;
}