#include <stdio.h>

int main() {
	int N = 0, in[100001][2] = { 0 }, heap[100001] = { 0 }, change = 0, time = 0, count = 0;
	scanf("%d", &N);
	for (int t = 1; t <= N; t++) {
		scanf("%d %d", &in[t][0], &in[t][1]);
		heap[0]++;
		heap[heap[0]] = t;
		for (int fix = heap[0]; fix > 1; fix /= 2) {
			if (in[heap[fix]][1] < in[heap[fix / 2]][1] || (in[heap[fix]][1] == in[heap[fix / 2]][1] && in[heap[fix]][0] < in[heap[fix / 2]][0])) {
				change = heap[fix];
				heap[fix] = heap[fix / 2];
				heap[fix / 2] = change;
			}
			else break;
		}
	}
	for (; heap[0] > 0;) {
		if (time <= in[heap[1]][0]) {
			count++;
			time = in[heap[1]][1];
		}
		heap[1] = heap[heap[0]];
		heap[heap[0]] = 0;
		heap[0]--;
		for (int fix = 1; fix * 2 + 1 <= heap[0];) {
			if (in[heap[fix * 2]][1] < in[heap[fix * 2 + 1]][1] || (in[heap[fix * 2]][1] == in[heap[fix * 2 + 1]][1] && in[heap[fix * 2]][0] < in[heap[fix * 2 + 1]][0])) {
				if (in[heap[fix * 2]][1] < in[heap[fix]][1] || (in[heap[fix * 2]][1] == in[heap[fix]][1] && in[heap[fix * 2]][0] < in[heap[fix]][0])) {
					change = heap[fix * 2];
					heap[fix * 2] = heap[fix];
					heap[fix] = change;
					fix *= 2;
				}
				else break;
			}
			else {
				if (in[heap[fix * 2 + 1]][1] < in[heap[fix]][1] || (in[heap[fix * 2 + 1]][1] == in[heap[fix]][1] && in[heap[fix * 2 + 1]][0] < in[heap[fix]][0])) {
					change = heap[fix];
					heap[fix] = heap[fix * 2 + 1];
					heap[fix * 2 + 1] = change;
					fix = fix * 2 + 1;
				}
				else break;
			}
		}
		if (heap[0] % 2 == 0 && (in[heap[heap[0]]][1] < in[heap[heap[0] / 2]][1] || (in[heap[heap[0]]][1] == in[heap[heap[0] / 2]][1] && in[heap[heap[0]]][0] < in[heap[heap[0] / 2]][0]))) {
			change = heap[heap[0]];
			heap[heap[0]] = heap[heap[0] / 2];
			heap[heap[0] / 2] = change;
		}
	}
	printf("%d", count);
	return 0;
}