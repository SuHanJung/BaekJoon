#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare(int a, int b) {
	if (a > b) return b;
	else return a;
}
int sorting(int input[], int answer[], int n, int size) {
	int l = size / 2, instarr[1000001] = { 0 };
	for (int time = 0; time + 1 <= n / size; time++) {
		for (int sa = time * size, sb = time * size + l,move = 0; move < size;) {
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
	int n = 0, answer[1000001] = { 0 }, input[1000001] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) answer[i] = i;
	for (int t = 0; t < n; t++) scanf("%d", &input[t]);
	Jsort(input, answer, n);
	for (int i = 0, last = 0, num = 0; i < n; i++) {
		if ((i == n - 1)  || (input[answer[i]] != input[answer[i + 1]])) {
			for (int k = last; k <= i; k++) {
				input[answer[k]] = num;
			}
			num++;
			last = i + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", input[i]);
	}
	return 0;
}