#include <stdio.h>
#include <malloc.h>
int MergeSorting(int* arr, int n, int cell) {
	int* storage = (int*)malloc(sizeof(int) * (n + 1));
	for (int start = 0; start + cell < n; start += 2 * cell) {
		for (int left = 0, right = 0, end = (start + cell * 2 < n) ? cell : n - start - cell;;) {
			if (arr[start + left] > arr[start + cell + right]) {
				storage[start + left + right] = arr[start + cell + right];
				right++;
			}
			else {
				storage[start + left + right] = arr[start + left];
				left++;
			}
			if (right >= end) {
				for (; left < cell; left++) storage[start + left + right] = arr[start + left];
				break;
			}
			else if (left >= cell) {
				for (; right < end; right++) storage[start + left + right] = arr[start + cell + right];
				break;
			}
		}
	}
	if (n % (cell * 2) <= cell) for (int t = 0, end = (n / (cell * 2)) * cell * 2; t < end; t++) arr[t] = storage[t];
	else for (int t = 0; t < n; t++) arr[t] = storage[t];
	free(storage);
	return 0;
}

void MergeSort(int* arr, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, n, cell);
	}
	return;
}

int main() {
	int N, M, arr[10] = { 0 }, ans[10] = { 0 };
	scanf("%d %d", &N, &M);
	for (int t = 1; t <= N; t++) {
		scanf("%d", &arr[t]);
		ans[t] = t;
	}
	MergeSort(arr, N + 1);
	for (int t = 1; t <= M; t++) printf("%d ", arr[ans[t]]);
	printf("\n");
	for (int mov = M, piv = (M == N) ? M : mov + 1;;piv++) {
		if (ans[piv] > ans[mov]) {
			ans[piv] += ans[mov];
			ans[mov] = ans[piv] - ans[mov];
			ans[piv] -= ans[mov];
			for (int t = 1; t <= M; t++) printf("%d ", arr[ans[t]]);
			printf("\n");
			if (mov != M) {
				mov = M;
				piv = M;
			}
		}
		if (piv == N) {
			if (mov == 1) return 0;
			ans[N + 1] = ans[mov];
			for (int t = mov; t <= N; t++) ans[t] = ans[t + 1];
			mov--;
			piv = mov;
		}
	}
	return 0;
}