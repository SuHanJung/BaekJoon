#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) {
	if (a > b) return b;
	else return a;
}
int sorting(int input[], int n, int size) {
	int l = size / 2, * instarr;
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
	int n = 0, *input, ran = 0, ans = 0;
	scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
	input = (int*)malloc(sizeof(int) * n);
	ran = n * 3;
	ran += 10;
	ran /= 20;
	for (int t = 0; t < n; t++) scanf("%d", &input[t]);
	Jsort(input, n);
	for (int t = ran; t < n - ran; t++) ans += input[t];
	ran = n - 2 * ran;
	if (ans % ran >= (ran + 1) / 2) {
		ans /= ran;
		ans++;
	}
	else ans /= ran;
	printf("%d", ans);
	free(input);
	return 0;
}