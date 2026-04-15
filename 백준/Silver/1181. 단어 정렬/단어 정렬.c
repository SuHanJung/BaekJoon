#include <stdio.h>
#include <malloc.h>
int compare(char a[], char b[]) {
	for (int t = 0; t < 53; t++) {
		if (a[t] < b[t]) return -1;
		else if (a[t] > b[t])return 1;
	}
	return 0;
}
int MergeSorting(char arr[][53], int* ans, int n, int cell) {
	int* storage = (int*)malloc(sizeof(int) * n);
	for (int start = 0; start + cell < n; start += 2 * cell) {
		for (int left = 0, right = 0, end = (start + cell * 2 < n) ? cell : n - start - cell;;) {
			if (compare(arr[ans[start + left]], arr[ans[start + cell + right]]) == 1) {
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

void MergeSort(char arr[][53], int* ans, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, ans, n, cell);
	}
	return;
}
int main() {
	char arr[20000][53] = { 0 };
	int ans[20000] = { 0 }, N;
	scanf("%d", &N);
	for (int t = 0; t < N; t++) {
			scanf("%s", &arr[t][1]);
			arr[t][0] = 1;
			for (; arr[t][arr[t][0]] != 0; arr[t][0]++);
			ans[t] = t;
	}
	MergeSort(arr, ans, N);
	printf("%s\n", &arr[ans[0]][1]);
	for (int t = 1; t < N; t++) if(compare(arr[ans[t]], arr[ans[t - 1]]) != 0) printf("%s\n", &arr[ans[t]][1]);
	return 0;
}