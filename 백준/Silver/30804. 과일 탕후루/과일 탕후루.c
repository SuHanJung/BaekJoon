#include <stdio.h>
#include <malloc.h>

int main() {
	int N, *arr, inst, max = 0;
	scanf("%d", &N);
	arr = malloc(sizeof(int) * 2 * (N + 1));
	arr[0] = 0;
	arr[N] = 0;
	for (int t = 0; t < N; t++) {
		scanf("%d", &inst);
		if (arr[arr[0] + N] == inst) arr[arr[0]]++;
		else {
			arr[++arr[0]] = 1;
			arr[arr[0] + N] = inst;
		}
	}
		for (int t = 1, a = arr[N + 1], b = arr[N + 2], n = 0; t <= arr[0]; t++) {
		if (arr[t + N] == a || arr[t + N] == b) n += arr[t];
		else {
			a = arr[t - 1 + N];
			b = arr[t + N];
			n = arr[t - 1] + arr[t];
		}
		if (n > max) max = n;
	}
	printf("%d", max);
	free(arr);
	return 0;
}