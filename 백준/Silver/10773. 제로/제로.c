#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num[1000001] = { 0 }, input = 0, ans = 0;
	scanf("%d", &input);
	num[0] = 0;
	for (int time = 0, n; time < input; time++) {
		scanf("%d", &n);
		if (n == 0) {
			num[num[0]] = 0;
			num[0]--;
		}
		else {
			num[0]++;
			num[num[0]] = n;
		}
	}
	for (int time = 1; time <= num[0]; time++) {
		ans += num[time];
	}
	printf("%d", ans);
	return 0;
}