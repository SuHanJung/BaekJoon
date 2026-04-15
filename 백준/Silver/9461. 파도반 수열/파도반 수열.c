#include <stdio.h>

int main() {
	unsigned long long int T = 0, N = 0, arr[101] = { 0 };
	scanf("%d", &T);
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int t = 6; t <= 100; t++) arr[t] = arr[t - 1] + arr[t - 5];
	for (int t = 0; t < T; t++) {
		scanf("%llu", &N);
		printf("%llu\n", arr[N]);
	}
	return 0;
}