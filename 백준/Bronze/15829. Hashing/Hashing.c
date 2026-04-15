#include <stdio.h>
int main() {
	long long int n = 0, inst = 0, ans = 0;
	char string[51] = { 0 };
	scanf("%d", &n);
	scanf("%s", string);
	for (int t = 0; t < n; t++) {
		inst = string[t] - 96;
		for (int re = 0; re < t; re++) {
			inst *= 31;
			inst = inst % 1234567891;
		}
		ans += inst;
		ans = ans % 1234567891;
	}
	printf("%d", ans);
	return 0;
}