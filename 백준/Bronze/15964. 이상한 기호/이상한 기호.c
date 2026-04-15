#include <stdio.h>
int main() {
	long long int a = 0, b = 0;
	scanf("%lld %lld", &a, &b);
	printf("%lld", (a * a) - (b * b));
	return 0;
}