#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int main() {
	int N, * inputA, * inputB, * num, * Node;
	scanf("%d", &N);
	inputA = malloc(sizeof(int) * N);
	inputB = malloc(sizeof(int) * N);
	num = malloc(sizeof(int) * (N + 2));
	for (int t = 0; t <= N; t++) num[t] = 0;
	Node = malloc(sizeof(int) * 2 * (N + 1));
	for (int t = 0; t < N - 1; t++) {
		scanf("%d%d", &inputA[t], &inputB[t]);
		num[inputA[t] + 1]++;
		num[inputB[t] + 1]++;
	}
	for (int t = 3; t <= N; t++) num[t] += num[t - 1];
	for (int t = 0; t < N - 1; t++) {
		Node[num[inputA[t]]] = inputB[t];
		num[inputA[t]]++;
		Node[num[inputB[t]]] = inputA[t];
		num[inputB[t]]++;
	}
	free(inputA);
	free(inputB);
	int *q = malloc(sizeof(int) * 2 * N);
	int *ans = malloc(sizeof(int) * (N + 1));
	for (int t = 2; t <= N; t++) ans[t] = 0;
	ans[0] = 1;
	ans[1] = 1;
	q[0] = 1;
	q[1] = 1;
	for (int t = 1; t <= q[0]; t++) {
		for (int read = num[q[t] - 1]; read < num[q[t]]; read++) {
			if (ans[Node[read]] == 0) {
				ans[Node[read]] = q[t];
				q[++q[0]] = Node[read];
			}
		}
	}
	for (int t = 2; t <= N; t++) printf("%d\n", ans[t]);
	free(Node);
	free(q);
	free(num);
	free(ans);
	return 0;
}