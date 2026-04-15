#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int factorial(int n) {
	int ans = 1;
	for (int time = 1; time <= n; time++) ans *= time;
	return ans;
}

int main() {
	int n, r;
	scanf("%d %d", &n, & r);
	printf("%d", (factorial(n) / factorial(r)) / factorial(n - r));
	return 0;
}