#include <stdio.h>
int main() {
	int T = 0, M = 0, N = 0, K = 0, map[51][51] = { 0 }, q[2501] = { 0 }, st[2501] = { 0 }, ans = 0;
	scanf("%d", &T);
	for (; T > 0; T--) {
		scanf("%d %d %d", &M, &N, &K);
		for (int t = 0, x = 0, y = 0; t < K; t++) {
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
			q[0]++;
			q[q[0]] = x * 100 + y;
		}

		for (int t = 1, x = 0, y = 0;;) {
			if (st[0] == 0) {
				for (; t <= K; t++) {
					x = q[t] / 100;
					y = q[t] % 100;
					if (map[x][y] == 1) break;
				}
				map[x][y] = 0;
				if (t > K) break;
				ans++;
			}
			else {
				x = st[st[0]] / 100;
				y = st[st[0]] % 100;
				st[st[0]] = 0;
				st[0]--;
			}
			if (x > 0 && map[x - 1][y] == 1) {
				map[x - 1][y] = 0;
				st[0]++;
				st[st[0]] = (x - 1) * 100 + y;
			}
			if (x < M - 1 && map[x + 1][y] == 1) {
				map[x + 1][y] = 0;
				st[0]++;
				st[st[0]] = (x + 1) * 100 + y;
			}
			if (y > 0 && map[x][y - 1] == 1) {
				map[x][y - 1] = 0;
				st[0]++;
				st[st[0]] = x * 100 + y - 1;
			}
			if (y < N - 1 && map[x][y + 1] == 1) {
				map[x][y + 1] = 0;
				st[0]++;
				st[st[0]] = x * 100 + y + 1;
			}
		}
		printf("%d\n", ans);
		ans = 0;
		for (int t = q[0]; t >= 0; t--) q[t] = 0;
	}
	return 0;
}