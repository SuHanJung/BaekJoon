#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime_num(unsigned int n, int prime[], int pn) {
	if (n < 2) return 0;
	for (int time = 0; prime[time] * prime[time] <= n; time++) {
		if (n % prime[time] == 0) return 0;
	}
	return 1;
}

int main() {
	int n = 0, pn = 5, prime[100000] = { 0 }, nn = 0, ans = 0;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11;
	scanf("%d", &nn);
	for (int rew = 0; rew < nn; rew++) {
		scanf("%d", &n);
		if (n / 2 > prime[pn - 1]) {
			for (int ne = prime[pn - 1] + 1; prime[pn - 1] <= n / 2; ne++) {
				if (prime_num(ne, prime, pn) == 1) {
					prime[pn] = ne;
					pn++;
				}
			}
		}
		for (int time = 0; prime[time] <= n / 2; time++) {
			if (prime_num(n - prime[time], prime, pn) == 1) ans++;
		}
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}