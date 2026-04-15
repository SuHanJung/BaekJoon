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
	int a = 0, b = 0, c = 0, d = 0, ans[2] = { 0 }, gr = 0;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	ans[0] = (a * d) + (b * c);
	ans[1] = b * d;
	gr = G_(ans[0], ans[1]);
	ans[0] /= gr;
	ans[1] /= gr;
	printf("%d %d", ans[0], ans[1]);
	return 0;
}