#include <stdio.h>
int main() {
	long long int a, b, c, arr[33], ans = 1;
	scanf("%lld %lld %lld", &a, &b, &c);
	a %= c;
	arr[0] = a;
	for (long long int t = 1; t <= 32; t++) {
		arr[t] = arr[t - 1] * arr[t - 1] % c;
	}
	for (long long int t = 0; b > 0; b /= 2, t++) {
		if (b % 2 == 1) {
			ans = ans * arr[t] % c;
		}
	}
	printf("%lld", ans);
	return 0;
}