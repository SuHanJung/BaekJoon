#include <stdio.h>

int main() {
	int in[101][101] = { 0 }, N = 0, st[101] = { 0 };
	scanf("%d", &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) scanf("%d", &in[y][x]);
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (in[y][x] == 1) {
				st[0]++;
				st[st[0]] = x;
			}
		}
		for (int t = 1; t <= N; t++) {
			if (in[t][y] == 1) {
				for (int tt = 1; tt <= st[0]; tt++) in[t][st[tt]] = 1;
			}
		}
		st[0] = 0;
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) printf("%d ", in[y][x]);
		printf("\n");
	}
	return 0;
}