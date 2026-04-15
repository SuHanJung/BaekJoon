#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	long long int K = 0, N = 0, * input, ans = 0, total = 0, ch = 0;
	scanf("%lld %lld", &K, &N);
	input = (long long int*)malloc(sizeof(long long int) * K);
	for (long long int scanner = 0; scanner < K; scanner++) {
		scanf("%lld", &input[scanner]);
		total += input[scanner];
	}
	ans = total / N;
ans += 1;
	for (long long int t = 0; t < K; t++) ch += input[t] / ans;
	if (ch == N) {
		printf("%lld", ans);
		return 0;
	}
	for (long long int check = 0, min = 1, max = ans, pivot = 0;;) {
		pivot = (min + max) / 2;
		check = 0;
		for (long long int t = 0; t < K; t++) check += input[t] / pivot;
		if (check >= N) min = pivot;
		else max = pivot;
		if (max - min <= 1) {
			ans = min;
			break;
		}
	}
	printf("%lld", ans);
	free(input);
	return 0;
}