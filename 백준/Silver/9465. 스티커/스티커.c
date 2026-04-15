#include <stdio.h>
#include <malloc.h>
int main() {
	int T, n, * line[2];
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &n);
		line[0] = malloc(sizeof(int) * n);
		line[1] = malloc(sizeof(int) * n);
		for (int t = 0; t < n; t++) scanf("%d", &line[0][t]);
		for (int t = 0; t < n; t++) scanf("%d", &line[1][t]);
		line[0][1] += line[1][0];
		line[1][1] += line[0][0];
		for (int t = 2; t < n; t++) {
			for (int num = 0, biggest; num <= 1; num++) {
				biggest = (line[1 - num][t - 1] > line[1 - num][t - 2]) ? line[1 - num][t - 1] : line[1 - num][t - 2];
				line[num][t] += biggest;
			}
		}
		printf("%d\n", (line[0][n - 1] > line[1][n - 1]) ? line[0][n - 1] : line[1][n - 1]);
		free(line[0]);
		free(line[1]);
	}
	return 0;
}