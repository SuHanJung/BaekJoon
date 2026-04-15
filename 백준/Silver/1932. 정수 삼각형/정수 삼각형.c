#include <stdio.h>
int main() {
	int n, input[501][501];
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		for (int tt = 1; tt <= t; tt++) scanf("%d", &input[t][tt]);
	}
	for (int t = n - 1; t > 0; t--) {
		for (int tt = 1; tt <= t; tt++) input[t][tt] += (input[t + 1][tt] > input[t + 1][tt + 1]) ? input[t + 1][tt] : input[t + 1][tt + 1];
	}
	printf("%d", input[1][1]);
	return 0;
}