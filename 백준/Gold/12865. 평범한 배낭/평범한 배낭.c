#include <stdio.h>
#include <malloc.h>

int MergeSorting(int* arr, int* ans, int n, int cell) {
	int* storage = (int*)malloc(sizeof(int) * n);
	for (int start = 0; start + cell < n; start += 2 * cell) {
		for (int left = 0, right = 0, end = (start + cell * 2 < n) ? cell : n - start - cell;;) {
			if (arr[ans[start + left]] > arr[ans[start + cell + right]]) {
				storage[start + left + right] = ans[start + cell + right];
				right++;
			}
			else {
				storage[start + left + right] = ans[start + left];
				left++;
			}
			if (right >= end) {
				for (; left < cell; left++) storage[start + left + right] = ans[start + left];
				break;
			}
			else if (left >= cell) {
				for (; right < end; right++) storage[start + left + right] = ans[start + cell + right];
				break;
			}
		}
	}
	if (n % (cell * 2) <= cell) for (int t = 0, end = (n / (cell * 2)) * cell * 2; t < end; t++) ans[t] = storage[t];
	else for (int t = 0; t < n; t++) ans[t] = storage[t];
	free(storage);
	return 0;
}

void MergeSort(int* arr, int* ans, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, ans, n, cell);
	}
	return;
}

void mov(int* w, int* v, int* ans, int N) {
	int* storage1 = malloc(sizeof(int) * N);
	int* storage2 = malloc(sizeof(int) * N);
	for (int t = 0; t < N; t++) {
		storage1[t] = w[ans[t]];
		storage2[t] = v[ans[t]];
	}
	for (int t = 0; t < N; t++) {
		w[t] = storage1[t];
		v[t] = storage2[t];
	}
	free(storage1);
	free(storage2);
}

int main() {
	int N, K, * w, * v, * ans, dp[1000001][101] = { 0 };
	scanf("%d %d", &N, &K);
	w = malloc(sizeof(int) * N);
	v = malloc(sizeof(int) * N);
	ans = malloc(sizeof(int) * N);
	for (int t = 0; t < N; t++) {
		ans[t] = t;
		scanf("%d %d", &w[t], &v[t]);
	}
	MergeSort(w, ans, N);
	mov(w, v, ans, N);
	if (K < w[0]) {
		printf("0");
		free(ans);
		free(w);
		free(v);
		return 0;
	}
	free(ans);
	for (int i = w[0]; i <= K; i++) {
		dp[i][0] = v[0];
		for (int t = 1; t < N; t++) {
			dp[i][t] = dp[i][t - 1];
			if (i - w[t] >= 0 && dp[i - w[t]][t - 1] + v[t] > dp[i][t]) dp[i][t] = dp[i - w[t]][t - 1] + v[t];
		}
	}
	printf("%d", dp[K][N - 1]);
	free(w);
	free(v);
	return 0;
}