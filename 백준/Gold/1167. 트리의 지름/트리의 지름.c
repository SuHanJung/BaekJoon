#include <stdio.h>
#include <malloc.h>

struct Node {
	int size;
	int* con;
	int* dis;
};

int main() {
	int V, * node, * distance, * ans, *q, start = 1;
	scanf("%d", &V);
	node = malloc(sizeof(int) * (V + 1));
	distance = malloc(sizeof(int) * (V + 1));
	struct Node* dot = malloc(sizeof(struct Node) * (V + 1));
	for (int t = 0, count, n; t < V; t++) {
		scanf("%d", &n);
		for (count = 0;; count++) {
			scanf("%d", &node[count]);
			if (node[count] == -1) {
				dot[n].size = count;
				dot[n].con = malloc(sizeof(int) * count);
				dot[n].dis = malloc(sizeof(int) * count);
				for (int copy = 0; copy < count; copy++) {
					dot[n].con[copy] = node[copy];
					dot[n].dis[copy] = distance[copy];
				}
				break;
			}
			scanf("%d", &distance[count]);
		}
	}
	free(node);
	free(distance);
	ans = malloc(sizeof(int) * (V + 1));
	q = malloc(sizeof(int) * (V + 2));
	for (int time = 0; time < 2; time++) {
		for (int t = 0; t <= V; t++) ans[t] = -1;
		q[0] = 1;
		q[1] = start;
		ans[start] = 0;
		for (int now = 1; now <= q[0]; now++) {
			for (int piv = 0; piv < dot[q[now]].size; piv++) {
				if (ans[dot[q[now]].con[piv]] == -1) {
					q[++q[0]] = dot[q[now]].con[piv];
					ans[dot[q[now]].con[piv]] = ans[q[now]] + dot[q[now]].dis[piv];
				}
			}
		}
		for (int t = 1; t <= V; t++) if (ans[t] > ans[start]) start = t;
	}
	printf("%d", ans[start]);
	free(ans);
	free(q);
	free(dot);
	return 0;
}