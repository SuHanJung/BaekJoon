#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input = 0,H = 0, W = 0, N = 0;
	scanf("%d", &input);
	for (int count = 0, ans = 0; count < input; count++) {
		scanf("%d %d %d", &H, &W, &N);
		if (N % H == 0) ans = (100 * (H)) + (N / H);
		else ans = (100 * (N % H)) + ((N / H) + 1);
		printf("%d", ans);
		if (count != input - 1) printf("\n");
	}
	return 0;
}