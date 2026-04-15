#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0, r = 0, c = 0, l = 1, arr[16] = { 0 }, ans = 0;
	scanf("%d %d %d", &N, &c, &r);
	for (int t = 0; t < N; t++, l *= 2);
	r++;
	c++;
	for (int t = 0; l >= 2;t++, l /= 2) {
		if (r > l / 2) {
			r -= l / 2;
			if (c > l / 2) {
				c -= l / 2;
				arr[t] = 3;
			}
			else arr[t] = 1;
		}
		else {
			if (c > l / 2) {
				c -= l / 2;
				arr[t] = 2;
			}
			else arr[t] = 0;
		}
	}
	for (int t = 0, k = 1; t < N; t++) {
		ans *= 4;
		ans += arr[t];
	}
	printf("%d", ans);
	return 0;
}