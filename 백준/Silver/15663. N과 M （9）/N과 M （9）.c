#include <stdio.h>
#include <malloc.h>
int MergeSorting(int* arr, int n, int cell) {
	int* storage = (int*)malloc(sizeof(int) * n);
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
	int M, N, input[10] = { 0 };
	scanf("%d %d", &N, &M);
	for (int t = 1; t <= N; t++) scanf("%d", &input[t]);
	MergeSort(input, N + 1);
	for (int mov = M, piv = M;mov > 0;) {
		for (int t = 1; t <= M; t++) printf("%d ", input[t]);
		printf("\n");
		for (;mov > 0;) {
			if (piv < N) {
				piv++;
				if (input[piv] > input[mov]) {
					input[piv] += input[mov];
					input[mov] = input[piv] - input[mov];
					input[piv] -= input[mov];
					if (mov != M) {
						mov = M;
						piv = mov;
					}
					break;
				}
			}
			else {
				input[N + 1] = input[mov];
				for (int t = mov; t <= N; t++) input[t] = input[t + 1];
				mov--;
				piv = mov;
			}
		}
	}
	return 0;
}