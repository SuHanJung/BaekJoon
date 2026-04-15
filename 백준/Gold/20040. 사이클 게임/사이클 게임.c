#include <stdio.h>
#include <malloc.h>
int* node;
int findParent(int n) {
	if (node[n] != n) node[n] = findParent(node[n]);
	return node[n];
}

int main() {
	int n, m, left, right, ans = 0;
	scanf("%d%d", &n, &m);
	node = malloc(sizeof(int) * n);
	for (int t = 0; t < n; t++) node[t] = t;
	for (int t = 1, val; t <= m;t++) {
		scanf("%d%d", &left, &right);
		val = findParent(left);
		if (val == findParent(right)) {
			ans = t;
			break;
		}
		else node[node[right]] = val;
	}
	printf("%d", ans);
	free(node);
	return 0;
}