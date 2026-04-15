#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0, b = 0;
	char p[101] = { 0 }, q = '0';
	scanf("%d", &a);
	scanf("%s", &p);
	for (int i = 0; i < a; i++) {
		b = b + p[i] - q;
	}
	printf("%d", b);
	return 0;
}