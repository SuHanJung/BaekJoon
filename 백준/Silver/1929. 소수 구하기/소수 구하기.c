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
	int n[2] = { 0 }, pn = 5, prime[100000] = { 0 };
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11;
	scanf("%d %d", &n[0], &n[1]);
		if (n[1] > 11) {
			for (int ne = prime[pn - 1] + 1; prime[pn - 1] <= n[1]; ne++) {
				if (prime_num(ne, prime, pn) == 1) {
					prime[pn] = ne;
					pn++;
				}
			}
		}
		for (int time = 0; prime[time] <= n[1]; time++) {
			if (prime[time] >= n[0]) printf("%d\n", prime[time]);
		}
	return 0;
}