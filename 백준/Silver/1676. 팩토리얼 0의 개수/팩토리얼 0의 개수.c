#include <stdio.h>
int main() {
	int input = 0, ans = 0;
	scanf("%d", &input);
	for (; input >= 5; input /= 5) ans += input / 5;
	printf("%d", ans);
	return 0;
}