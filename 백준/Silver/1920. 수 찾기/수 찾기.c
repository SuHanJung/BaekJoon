#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int searching(int list[],int n,int val) {
	int piv = 0, maxi = n - 1, mini = 0;
	for (; maxi - mini > 1;) {
		piv = (maxi + mini) / 2;
		if (list[piv] == val) return 1;
		else if (list[piv] > val) maxi = piv;
		else mini = piv;
	}
	if ((list[maxi] == val) || (list[mini] == val)) return 1;
	return 0;
}

int compare(int a, int b) {
	if (a > b) return b;
	else return a;
}
int sorting(int input[], int n, int size) {
	int l = size / 2, *instarr;
	instarr = malloc(sizeof(int) * n);
	for (int time = 0; time + 1 <= n / size; time++) {
		for (int sa = time * size, sb = time * size + l, move = 0; move < size;) {
			if (sa == time * size + l) {
				instarr[time * size + move] = input[sb];
				sb++;
			}
			else {
				if (sb == (time + 1) * size) {
					instarr[time * size + move] = input[sa];
					sa++;
				}
				else {
					if (compare(input[sa], input[sb]) == input[sa]) {
						instarr[time * size + move] = input[sa];
						sa++;
					}
					else {
						instarr[time * size + move] = input[sb];
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
				instarr[(n / size) * size + move] = input[sb];
				sb++;
			}
			else {
				if (sb == n) {
					instarr[(n / size) * size + move] = input[sa];
					sa++;
				}
				else {
					if (compare(input[sa], input[sb]) == input[sa]) {
						instarr[(n / size) * size + move] = input[sa];
						sa++;
					}
					else {
						instarr[(n / size) * size + move] = input[sb];
						sb++;
					}
				}
			}
			move++;
		}
	}
	else {
		for (int i = (n / size) * size; i < n; i++) instarr[i] = input[i];
	}
	for (int i = 0; i < n; i++) input[i] = instarr[i];
	free(instarr);
	return 0;
}

int Jsort(int input[], int n) {
	for (int i = 1; i < n; i *= 2) {
		sorting(input, n, 2 * i);
	}
}

int main() {
	int m = 0, n = 0, val = 0, *input;
	scanf("%d", &n);
	input = malloc(sizeof(int) * n);
	for (int time = 0; time < n; time++) scanf("%d", &input[time]);
	Jsort(input, n);
	scanf("%d", &m);
	for (int time = 0; time < m; time++) {
		scanf("%d", &val);
		printf("%d\n", searching(input, n, val));
	}
	return 0;
}