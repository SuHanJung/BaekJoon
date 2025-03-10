#include <stdio.h>
#include <malloc.h>

int main() {
	int N, S, * arr, ans, end = 0;

	scanf("%d%d", &N, &S);
	arr = malloc(sizeof(int) * (N + 1));
	arr[0] = 0;
	for (int t = 1, input; t <= N; t++) {
		scanf("%d", &input);
		arr[t] = input + arr[t - 1];
	}
	if (arr[N] <= S) {
		if (arr[N] == S) printf("%d", N);
		else printf("0");
		return 0;
	}
	while (arr[end] < S) end++;
	ans = end - 1;
	for (int start = 0; end <= N;end++) {
		while (arr[end] - arr[start]>= S) start++;
		ans = (ans < end - start) ? ans : end - start;
	}
	printf("%d", ans + 1);
	return 0;
}