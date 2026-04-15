#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) {
	if (a > b) return b;
	else return a;
}
int sorting(int input[], int answer[], int n, int size) {
	int l = size / 2, instarr[51] = { 0 };
	for (int time = 0; time + 1 <= n / size; time++) {
		for (int sa = time * size, sb = time * size + l, move = 0; move < size;) {
			if (sa == time * size + l) {
				instarr[time * size + move] = answer[sb];
				sb++;
			}
			else {
				if (sb == (time + 1) * size) {
					instarr[time * size + move] = answer[sa];
					sa++;
				}
				else {
					if (compare(input[answer[sa]], input[answer[sb]]) == input[answer[sa]]) {
						instarr[time * size + move] = answer[sa];
						sa++;
					}
					else {
						instarr[time * size + move] = answer[sb];
						sb++;
					}
				}
			}
			move++;
		}
	}
	if (n % size > l) {
		for (int sa = (n / size) * size, sb = (n / size) * size + l, move = 0; move < n % size;) {
			if (sa == (n / size) * size + l) {
				instarr[(n / size) * size + move] = answer[sb];
				sb++;
			}
			else {
				if (sb == n) {
					instarr[(n / size) * size + move] = answer[sa];
					sa++;
				}
				else {
					if (compare(input[answer[sa]], input[answer[sb]]) == input[answer[sa]]) {
						instarr[(n / size) * size + move] = answer[sa];
						sa++;
					}
					else {
						instarr[(n / size) * size + move] = answer[sb];
						sb++;
					}
				}
			}
			move++;
		}
	}
	else {
		for (int i = (n / size) * size; i < n; i++) instarr[i] = answer[i];
	}
	for (int i = 0; i < n; i++) answer[i] = instarr[i];
	return 0;
}

int Jsort(int input[], int answer[], int n) {
	for (int i = 1; i < n; i *= 2) {
		sorting(input, answer, n, 2 * i);
	}
}

int main() {
	int n = 0, height[51] = { 0 }, weight[51] = { 0 }, ans[51] = { 0 }, input[51] = { 0 };
	scanf("%d", &n);
	for (int t = 0; t < n; t++) input[t] = t;
	for (int t = 0; t < n; t++) scanf("%d %d", &height[t], &weight[t]);
	Jsort(height, input, n);
	for (int t = n - 1; t >= 0; t--) {
		ans[input[t]] = 1;
		for (int tt = n - 1; height[input[tt]] > height[input[t]]; tt--) {
			if (weight[input[tt]] > weight[input[t]]) ans[input[t]]++;
		}
	}
	for (int t = 0; t < n; t++) printf("%d ", ans[t]);
	return 0;
}