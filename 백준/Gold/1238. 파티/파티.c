#include <stdio.h>
#include <malloc.h>

struct Node {
	int nums, nume, nows, nowe, *start, *end;
};

int main() {
	int N, M, X, *ins, *ine, *intime, *ans1, *ans2, *q, ans = 0;
	scanf("%d%d%d", &N, &M, &X);
	struct Node* node = malloc(sizeof(struct Node) * (N + 1));
	ins = malloc(sizeof(int) * 3 * M);
	ine = &ins[M];
	intime = &ine[M];
	for (int t = 1; t <= N; t++) {
		node[t].nums = 0;
		node[t].nume = 0;
		node[t].nows = 0;
		node[t].nowe = 0;
	}
	for (int t = 0; t < M; t++) {
		scanf("%d%d%d", &ins[t], &ine[t], &intime[t]);
		node[ins[t]].nums++;
		node[ine[t]].nume++;
	}
	node[1].start = malloc(sizeof(int) * M * 2);
	node[1].end = &node[1].start[M];
	for (int t = 2; t <= N; t++) {
		node[t].start = node[t - 1].start + node[t - 1].nums;
		node[t].end = node[t - 1].end + node[t - 1].nume;
	}
	for (int t = 0; t < M; t++) {
		node[ins[t]].start[node[ins[t]].nows++] = t;
		node[ine[t]].end[node[ine[t]].nowe++] = t;
	}
	ans1 = malloc(sizeof(int) * 4 * (N + 1));
	ans2 = &ans1[N + 1];
	q = &ans2[N + 1];
	for (int t = 1; t <= N; t++) {
		ans1[t] = -1;
		ans2[t] = -1;
	}
	ans1[X] = 0;
	ans2[X] = 0;
	q[0] = 1;
	q[1] = X;
	for (int t = 1, now; t <= q[0]; t++) {
		now = q[t];
		for (int tt = 0; tt < node[now].nums; tt++) {
			if (ans1[ine[node[now].start[tt]]] == -1 || ans1[now] + intime[node[now].start[tt]] < ans1[ine[node[now].start[tt]]]) {
				ans1[ine[node[now].start[tt]]] = ans1[now] + intime[node[now].start[tt]];
				q[++q[0]] = ine[node[now].start[tt]];
			}
		}
	}
	q[0] = 1;
	q[1] = X;
	for (int t = 1, now; t <= q[0]; t++) {
		now = q[t];
		for (int tt = 0; tt < node[now].nume; tt++) {
			if (ans2[ins[node[now].end[tt]]] == -1 || ans2[now] + intime[node[now].end[tt]] < ans2[ins[node[now].end[tt]]]) {
				ans2[ins[node[now].end[tt]]] = ans2[now] + intime[node[now].end[tt]];
				q[++q[0]] = ins[node[now].end[tt]];
			}
		}
	}
	for (int t = 1; t <= N; t++) if (ans1[t] + ans2[t] > ans) ans = ans1[t] + ans2[t];
	printf("%d", ans);
	free(ins);
	free(ans1);
	free(node[1].start);
	free(node);
	return 0;
}