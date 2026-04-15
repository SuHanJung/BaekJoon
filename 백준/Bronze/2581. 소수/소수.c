#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[3] = { 0 }, list[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 }, ans = 0;
	int k = 0;
	scanf("%d", &a[0]);
	scanf("%d", &a[1]);
	if (a[1] <= 100) {
		for (int t = 0; (t < 25) && (list[t] <= a[1]); t++) {
			if (list[t] >= a[0]) {
				if (ans == 0) k = list[t];
				ans += list[t];
			}
		}
	}
	else {
		if (a[0] > 100) {
			for (int t = a[0]; t <= a[1]; t++) {
				for (int i = 0;; i++) {
					if ((t % list[i] == 0)) {
						break;
					}
					if (list[i + 1] * list[i + 1] > t) {
						if (ans == 0) k = t;
						ans += t;
						break;
					}
				}
			}
		}
		else {
			a[2] = a[1];
			a[1] = 100;
			for (int t = 0; (t < 25) && (list[t] <= a[1]); t++) {
				if (list[t] >= a[0]) {
					if (ans == 0) k = list[t];
					ans += list[t];
				}
			}
			for (int t = a[1] + 1; t <= a[2]; t++) {
				for (int i = 0;; i++) {
					if ((t % list[i] == 0)) {
						break;
					}
					if (list[i + 1] * list[i + 1] > t) {
						if (ans == 0) k = t;
						ans += t;
						break;
					}
				}
			}

		}
	}
	if (ans == 0) printf("-1");
	else printf("%d\n%d", ans, k);
	return 0;
}