#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int map[15][15] = { 0 }, k = 0, n = 0, count = 0;
	for (int t = 0; t < 16; t++) {
		map[0][t] = t;
		map[t][1] = 1;
	}
	for (int t = 1; t < 15; t++) {
		for (int tt = 2; tt < 15; tt++) map[t][tt] = map[t][tt - 1] + map[t - 1][tt];
	}
	scanf("%d", &count);
	for (int c = 1; c <= count; c++) {
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d", map[k][n]);
		if(c != count) printf("\n");
	}
	return 0;
}