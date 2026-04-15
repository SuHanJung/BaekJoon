#include <stdio.h>
int main() {
	int q[10001] = { 0 }, st[10001] = { 0 }, N = 0, ans = 1, ch[101][101] = { 0 }, anss = 0;
	char gr[101][101] = { 0 };
	scanf("%d", &N);
	for (int t = 0; t < N; t++) scanf("%s", gr[t]);
	for (int count = 0; count < 2; count++) {
		q[0] = 1;
		ans = 0;
		for (int t = 1, x = 0, y = 0;;) {
			if (st[0] == 0) {
				for (;t <= q[0]; t++) {
					x = q[t] / 1000;
					y = q[t] % 1000;
					if (ch[x][y] == 0) break;
				}
				ch[x][y]++;
				if (q[0] < t) break;
				ans++;
			}
			else {
				x = st[st[0]] / 1000;
				y = st[st[0]] % 1000;
				st[st[0]] = 0;
				st[0]--;
			}
			if (x > 0) {
				if (ch[x - 1][y] == 0) {
					if (gr[x][y] == gr[x - 1][y]) {
					ch[x - 1][y]++;
						st[0]++;
						st[st[0]] = (x - 1) * 1000 + y;
					}
					else {
						q[0]++;
						q[q[0]] = (x - 1) * 1000 + y;
					}
				}
			}
			if (x < N - 1) {
				if (ch[x + 1][y] == 0) {
					if (gr[x][y] == gr[x + 1][y]) {
					ch[x + 1][y]++;
						st[0]++;
						st[st[0]] = (x + 1) * 1000 + y;
					}
					else {
						q[0]++;
						q[q[0]] = (x + 1) * 1000 + y;
					}
				}
			}
			if (y > 0) {
				if (ch[x][y - 1] == 0) {
					if (gr[x][y] == gr[x][y - 1]) {
					ch[x][y - 1]++;
						st[0]++;
						st[st[0]] = x * 1000 + (y - 1);
					}
					else {
						q[0]++;
						q[q[0]] = x * 1000 + (y - 1);
					}
				}
			}
			if (y < N - 1) {
				if (ch[x][y + 1] == 0) {
					if (gr[x][y] == gr[x][y + 1]) {
					ch[x][y + 1]++;
						st[0]++;
						st[st[0]] = x * 1000 + (y + 1);
					}
					else {
						q[0]++;
						q[q[0]] = x * 1000 + (y + 1);
					}
				}
			}
		}
		if(anss == 0) anss = ans;
		for (int k = 0; k < N; k++) {
			for (int kk = 0; kk < N; kk++) {
				ch[k][kk] = 0;
				if (gr[k][kk] == 'G') gr[k][kk] = 'R';
			}
		}
	}
	printf("%d %d", anss, ans);
	return 0;
}