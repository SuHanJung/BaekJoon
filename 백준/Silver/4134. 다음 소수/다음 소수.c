#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime_num(unsigned int n,unsigned int prime[], int pn) {
	if (n < 2) return 0;
	for (int time = 0; prime[time] * prime[time] <= n; time++) {
		if (n % prime[time] == 0) return 0;
	}
	return 1;
}

int main() {
	int n = 0, pn = 5;
	unsigned int input = 0, prime[100000] = { 0 }, ma = 121;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11;
	scanf("%d", &n);
	for (int time = 0; time < n; time++) {
		scanf("%u", &input);
		if (input > ma) {
			for (unsigned int ne = prime[pn - 1]; ma <= input; ne++) {
				if (prime_num(ne, prime, pn) == 1) {
					prime[pn] = ne;
					ma = ne * ne;
					pn++;
				}
			}
		}
		for (;; input++) {
			if (prime_num(input, prime, pn) == 1) {
				printf("%u\n", input);
				break;
			}
		}
	}
	return 0;
}