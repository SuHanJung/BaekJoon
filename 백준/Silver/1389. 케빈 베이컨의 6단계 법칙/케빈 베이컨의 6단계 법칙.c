#include <stdio.h>

int main() {
	int N = 0, M = 0, friends[101][101] = { 0 }, q[1000] = { 0 }, ch[101] = { 0 }, ans[2] = { 10000, 0 }, tot = 0;
	scanf("%d %d", &N, &M);
	for (int t = 0, inA = 0, inB = 0; t < M; t++) {
		scanf("%d %d", &inA, &inB);
		friends[inA][0]++;
		friends[inB][0]++;
		friends[inA][friends[inA][0]] = inB;
		friends[inB][friends[inB][0]] = inA;
	}
	for (int t = 1; t <= N; t++) {
		tot = 0;
		q[0] = 1;
		q[1] = t;
		for (int now = 1;now <= q[0];now++) {
			for (int read = 1; read <= friends[q[now]][0]; read++) {
				if (ch[friends[q[now]][read]] == 0) {
					q[0]++;
					q[q[0]] = friends[q[now]][read];
					ch[friends[q[now]][read]] = ch[q[now]] + 1;
				}
			}
		}
		ch[t] = 0;
		for (int pl = 1; pl <= N; pl++) tot += ch[pl];
		if (tot < ans[0]) {
			ans[0] = tot;
			ans[1] = t;
		}
		for (int re = 1; re <= N; re++) ch[re] = 0;
	}
	printf("%d", ans[1]);
	return 0;
}