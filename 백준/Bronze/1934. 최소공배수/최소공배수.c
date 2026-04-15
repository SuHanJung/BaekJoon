#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare(int a, int b) {
	if (a > b) return b;
	else return a;
}
int G_(int a, int b) {
	int G = 1, prime = 2, aa = a, bb = b;
	for (; compare(aa, bb) >= prime; prime++) {
		for (; ((aa % prime == 0) && (bb % prime == 0));) {
			G *= prime;
			aa /= prime;
			bb /= prime;
		}
	}
	return G;
}

int main() {
	int a = 0, b = 0, n =0, gr = 0;
    long long int le = 0;
	scanf("%d", &n);
	for (int time = 0; time < n; time++) {
		scanf("%d %d", &a, &b);
		gr = G_(a, b);
		le = (a * b) / gr;
		printf("%lld\n", le);
	}
	return 0;
}