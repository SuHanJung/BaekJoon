#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int N = 0, M = 0, W = 0, input[105] = { 0 }, ans = 1, L = 0, p = 0;
	scanf("%d", &N);
	for (int t = 0; t < N; t++) {
		scanf("%d %d", &M, &W);
		p = M - 1;
		for (int tt = 0; tt < M; tt++) scanf("%d", &input[tt]);
		for (int tt = 0; tt < M; tt++) {
			if (input[tt] > input[W]) {
				ans++;
				if (input[tt] >= L) L = input[tt];
			}
		}
		if (L == input[W] || L == 0) p = 0;
		else for (; L > input[W]; L--) {
			for (int k = p;; k--) {
				if (input[k] == L) {
					p = k;
					break;
				}
				if (k % M == (p + 1) % M) break;
				if (k == 0) k = M;
			}
		}
		for (int tt = p; tt % M != W % M; tt++) {
			if (input[tt % M] == input[W]) ans++;
		}
		printf("%d\n", ans);
		ans = 1;
		for (int tt = 0; tt < M; tt++) input[tt] = 0;
		M = 0;
		W = 0;
		L = 0;
	}
	return 0;
	}