#include <stdio.h>
int main() {
	int N = 0, M = 0, in[501][501] = { 0 }, ans = 0;
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for(int x = 0;x < M;x++){
			scanf("%d", &in[x][y]);
		}
	}
	for (int x = 0; x < M; x++) {
		for (int y = 0, inst = 0; y < N - 3; y++) {
			inst = in[x][y] + in[x][y + 1] + in[x][y + 2] + in[x][y + 3];
			ans = (ans > inst) ? ans : inst;
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0, inst = 0; x < M - 3; x++) {
			inst = in[x][y] + in[x + 1][y] + in[x + 2][y] + in[x + 3][y];
			ans = (ans > inst) ? ans : inst;
		}
	}
	for (int x = 0, inst = 0, s = 0; x < M - 2; x++) {
		for (int y = 0; y < N - 1; y++) {
			inst = 0;
			for (int t = x; t < x + 3; t++) {
				for (int tt = y; tt < y + 2; tt++) {
					inst += in[t][tt];
				}
			}
			s = (in[x][y] + in[x][y + 1] < in[x + 2][y] + in[x + 2][y + 1]) ? in[x][y] + in[x][y + 1] : in[x + 2][y] + in[x + 2][y + 1];
			s = (s < in[x][y] + in[x + 1][y]) ? s : in[x][y] + in[x + 1][y];
			s = (s < in[x + 2][y] + in[x + 1][y]) ? s : in[x + 2][y] + in[x + 1][y];
			s = (s < in[x][y + 1] + in[x + 1][y + 1]) ? s : in[x][y + 1] + in[x + 1][y + 1];
			s = (s < in[x + 2][y + 1] + in[x + 1][y + 1]) ? s : in[x + 2][y + 1] + in[x + 1][y + 1];
			s = (s < in[x][y] + in[x + 2][y]) ? s : in[x][y] + in[x + 2][y];
			s = (s < in[x][y + 1] + in[x + 2][y + 1]) ? s : in[x][y + 1] + in[x + 2][y + 1];
			s = (s < in[x][y] + in[x + 2][y + 1]) ? s : in[x][y] + in[x + 2][y + 1];
			s = (s < in[x][y + 1] + in[x + 2][y]) ? s : in[x][y + 1] + in[x + 2][y];
			inst -= s;
			ans = (ans > inst) ? ans : inst;
		}
	}
	for (int y = 0, inst = 0, s = 0; y < N - 2; y++) {
		for (int x = 0; x < M - 1; x++) {
			inst = 0;
			for (int t = x; t < x + 2; t++) {
				for (int tt = y; tt < y + 3; tt++) {
					inst += in[t][tt];
				}
			}
			s = (in[x][y] + in[x + 1][y] < in[x][y + 2] + in[x + 1][y + 2]) ? in[x][y] + in[x + 1][y] : in[x][y + 2] + in[x + 1][y + 2];
			s = (s < in[x][y] + in[x][y + 1]) ? s : in[x][y] + in[x][y + 1];
			s = (s < in[x][y + 2] + in[x][y + 1]) ? s : in[x][y + 2] + in[x][y + 1];
			s = (s < in[x + 1][y] + in[x + 1][y + 1]) ? s : in[x + 1][y] + in[x + 1][y + 1];
			s = (s < in[x + 1][y + 2] + in[x + 1][y + 1]) ? s : in[x + 1][y + 2] + in[x + 1][y + 1];
			s = (s < in[x][y] + in[x][y + 2]) ? s : in[x][y] + in[x][y + 2];
			s = (s < in[x + 1][y] + in[x + 1][y + 2]) ? s : in[x + 1][y] + in[x + 1][y + 2];
			s = (s < in[x][y] + in[x + 1][y + 2]) ? s : in[x][y] + in[x + 1][y + 2];
			s = (s < in[x + 1][y] + in[x][y + 2]) ? s : in[x + 1][y] + in[x][y + 2];
			inst -= s;
			ans = (ans > inst) ? ans : inst;
		}
	}
	printf("%d", ans);
	return 0;
}