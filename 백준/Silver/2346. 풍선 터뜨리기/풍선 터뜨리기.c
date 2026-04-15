#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int JQ_push(int q[], int x) {
	q[0]++;
	q[q[0]] = x;
	return 0;
}
int JQ_pop(int q[]) {
	int out;
	if (q[0] == 0) {
		out = -1;
	}
	else {
		out = q[1];
		q[0]--;
		for (int t = 1; t <= q[0]; t++) q[t] = q[t + 1];
		q[q[0] + 1] = 0;
	}
	return out;
}
int JQ_size(int q[]) {
	return q[0];
}
int JQ_empty(int q[]) {
	if (q[0] == 0) return 1;
	else return 0;
}
int JQ_front(int q[]) {
	if (q[0] == 0) return -1;
	else return q[1];
}
int JQ_back(int q[]) {
	if (q[0] == 0) return -1;
	else return q[q[0]];
}

int main() {
	int n = 0, a = 1, q[1001] = { 0 }, sc[1001] = { 0 };
	scanf("%d", &n);
	for (int t = 0; t <= n; t++) q[t] = t;
	for (int t = 1; t <= n; t++) scanf("%d", &sc[t]);
	q[0] = n;
	a = JQ_pop(q);
	printf("%d ", a);
	for (int time = 1, inst = 1; time < n; time++) {
		inst = sc[a];
		if (inst < 0) {
			for (; inst < 0;) inst += JQ_size(q);
			inst++;
		}
		for (int t = 1; t < inst; t++) {
			a = JQ_pop(q);
			JQ_push(q, a);
		}
		a = JQ_pop(q);
		printf("%d ", a);
	}
	return 0;
}