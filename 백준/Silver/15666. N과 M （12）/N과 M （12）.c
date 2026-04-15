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
	int N, M, input[9] = { 0 }, out[9] = { 0 };
	scanf("%d %d", &N, &M);

	for (int t = 0; t < N; t++) scanf("%d", &input[t]);
	MergeSort(input, N);
	for (int t = 1; t < N; t++) {
		if (input[t] == input[t - 1]) {
			for (int tt = t; tt < N; tt++) input[tt - 1] = input[tt];
			N--;
            t--;
		}
	}
	for (int piv = M - 1; piv >= 0;) {
		if (out[M - 1] != 0) printf("\n");
		for (int t = 0; t < M; t++) {
			printf("%d", input[out[t]]);
			if (t != M - 1) printf(" ");
		}
		out[piv]++;
		if (out[piv] >= N) {
			for (; out[piv] >= N - 1 && piv >= 0; piv--);
			if (piv >= 0) {
				out[piv]++;
				for (int t = piv + 1; t < M; t++) out[t] = out[piv];
				piv = M - 1;
			}
		}
	}
	return 0;
}