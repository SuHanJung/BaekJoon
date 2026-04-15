#include<malloc.h>

void MergeSorting(int* arr, int* ans, int n, int cell) {
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
}

void MergeSort(int* arr, int* ans, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, ans, n, cell);
	}
	return;
}

int main() {
	char input[101] = { 0 }, ans[101];
	int g[51] = { 0 }, arr[51], count;
	scanf("%s", input);
	for (int t = 0, p = 0;; t++) {
		if (input[t] == 0) {
			count = g[0];
			g[count + 1] = t;
			g[0] = -1;
			break;
		}
		switch (input[t]) {
		case '(':
			p += 2;
			break;
		case ')':
			p -= 2;
			break;
		case '*':
			g[++g[0]] = (p + 1) * 1000 + 100 -t;
			break;
		case '/':
			g[++g[0]] = (p + 1) * 1000 + 100 -t;
			break;
		case '+':
			g[++g[0]] = p * 1000 + 100 -t;
			break;
		case '-':		
			g[++g[0]] = p * 1000 + 100 -t;
			break;
		}
	}
	for (int t = 0; t < 50; t++) arr[t] = t;
	MergeSort(&g[1], arr, count);
	for (int t = 0; t < count; t++) {
		arr[t]++;
		g[t + 1] %= 1000;
		g[t + 1] = 100 - g[t + 1];
	}
	
	for (int t = count - 1, n, prev, next; t >= 0; t--) {
		n = arr[t];
		for (prev = n - 1; g[prev] == -1000; prev--);
		for (next = n + 1; g[next] == -1000; next++);
		for (int scan = g[prev] + 1; scan < g[n]; scan++) ans[scan] = input[scan];
		for (int scan = g[n] + 1; scan < g[next]; scan++) ans[scan - 1] = input[scan];
		ans[g[next] - 1] = input[g[n]];
		for (int scan = g[prev] + 1; scan < g[next]; scan++) input[scan] = ans[scan];
		g[n] = -1000;
	}
	for (int t = 0; t < g[count + 1]; t++) if (input[t] != '(' && input[t] != ')')
		printf("%c", input[t]);
	return 0;
}