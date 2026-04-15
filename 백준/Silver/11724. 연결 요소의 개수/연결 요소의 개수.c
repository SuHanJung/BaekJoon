#include <stdio.h>

int main() {
	int N = 0, M = 0, com[1001][1000] = { 0 }, ch[1001] = { 0 }, ans = 0, q[1001] = { 0 };
	scanf("%d %d", &N, &M);
	for (int t = 0, a = 0, b = 0; t < M; t++) {
		scanf("%d %d", &a, &b);
		com[a][0]++;
		com[b][0]++;
		com[a][com[a][0]] = b;
		com[b][com[b][0]] = a;
	}
	for (int check = 1; check <= N; check++) {
		if (ch[check] == 0) {
			ans++;
			q[0] = 1;
			q[1] = check;
			for (int t = 1;t <= q[0];t++) {
				for (int read = 1; read <= com[q[t]][0]; read++) {
					if (ch[com[q[t]][read]] == 0) {
						ch[com[q[t]][read]] = 1;
						q[0]++;
						q[q[0]] = com[q[t]][read];
					}
				}
			}
			q[0] = 0;
		}
	}
	printf("%d", ans);
	return 0;
}