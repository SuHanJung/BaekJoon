#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	long long int a, b, c, La;
	for (;;) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if ((a == 0) && (b == 0) && (c == 0)) return 0;
		La = compare(a, compare(b, c));
		if (La * La * 2 == a * a + b * b + c * c) printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}