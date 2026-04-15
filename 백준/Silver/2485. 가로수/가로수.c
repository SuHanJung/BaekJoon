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
	int n = 0, gr = 0, *input;
	scanf("%d", &n);
	input = malloc(sizeof(int) * n);
	for (int time = 0; time < n; time++) scanf("%d", &input[time]);
	gr = input[1] - input[0];
	for (int time = 2; time < n; time++) gr = G_(gr, input[time] - input[time - 1]);
	printf("%d", ((input[n - 1] - input[0]) / gr) - n + 1);
	return 0;
}