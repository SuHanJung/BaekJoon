#include <stdio.h>
#include <malloc.h>
int main() {
	int M, N, *piv;
	scanf("%d %d", &M, &N);
	piv = malloc(sizeof(int) * (N + 2));
	piv[N + 1] = M + 1;
	for (int t = 1; t <= N; t++) piv[t] = t;
	for (; piv[1] <= M - N + 1;) {
		for (int t = 1; t <= N; t++) printf("%d ", piv[t]);
		printf("\n");
		if (piv[1] == M - N + 1) break;
		for (int mov = N; mov >= 1; mov--) {
			if (piv[mov + 1] > piv[mov] + 1) {
				piv[mov]++;
				for (int t = mov + 1; t <= N; t++) piv[t] = piv[t - 1] + 1;
				break;
			}
		}
	}
	return 0;
}