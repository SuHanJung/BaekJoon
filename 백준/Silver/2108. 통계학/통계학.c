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
	long long int ans = 0, k = 0, kk = 0;
	int * input, n = 0;
    scanf("%lld", &n);
	input = (int*)malloc(sizeof(int) * n);
	for (int t = 0; t < n; t++) scanf("%d", &input[t]);
	for (int t = 0; t < n; t++) ans += input[t];
	ans = ans * 10;
	ans /= n;
	if (ans > 0) {
		if (ans % 10 >= 5) printf("%lld\n", (ans / 10) + 1);
		else printf("%lld\n", ans / 10);
	}
	else {
		if (ans % 10 > -5) printf("%lld\n", ans / 10);
		else printf("%lld\n", (ans / 10) - 1);

	}
	Jsort(input, n);
	ans = input[n / 2];
	printf("%lld\n", ans);
	for (int t = 1, count = 1; t < n; t++) {
		if (input[t] == input[t - 1]) count++;
		if(input[t] != input[t - 1] || t == n - 1) {
			if (count > k) {
				ans = input[t - 1];
				k = count;
				kk = 0;
			}
			else if (count == k && kk == 0) {
				kk = ans;
				ans = input[t - 1];
			}
			count = 1;
		}
	}
	printf("%lld\n", ans);
	printf("%lld", input[n - 1] - input[0]);
	free(input);
	return 0;
}