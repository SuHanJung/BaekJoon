#include<stdio.h>
int main() {
	int N, input[1001][2] = { 0 };
	scanf("%d", &N);
	for (int t = 1; t <= N; t++) scanf("%d", &input[t][0]);
	for (int t = 1; t <= N; t++) {
		for (int tt = 0; tt < t; tt++) {
			if (input[tt][0] < input[t][0] && input[t][1] < input[tt][1] + 1) input[t][1] = input[tt][1] + 1;
		}
	}
	for (int max = 0, t = 0;; t++) {
		if (input[t][1] > max) max = input[t][1];
		if (t == N) {
			printf("%d", max);
			break;
		}
	}
	return 0;
}