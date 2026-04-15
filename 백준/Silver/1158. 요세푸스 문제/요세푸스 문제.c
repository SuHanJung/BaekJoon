#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0, K = 0, now = 0, arr[5001] = { 0 }, ans = 0;
	scanf("%d %d", &N, &K);
	now = K;
	for (int t = 0; t <= N; t++) arr[t] = t;
	printf("<");
	arr[0] = K;
	for (int NN = N;NN >= 1;) {
		printf("%d", arr[now]);
		if (NN - ans > 1) printf(", ");
		else printf(">");
		ans++;
		now++;
		if (now > NN) {
			now -= NN;
			NN -= ans;
			ans = 0;
			arr[0] = 1;
		}
		for (int t = 0; t < K - 1; t++) {
			arr[arr[0]] = arr[now];
			arr[0]++;
			now++;
			if (now > NN) {
				now -= NN;
				NN -= ans;
				ans = 0;
				arr[0] = 1;
			}
		}
	}
	return 0;
}