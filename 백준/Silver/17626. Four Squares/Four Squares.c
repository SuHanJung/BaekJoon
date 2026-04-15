#include <stdio.h>
int main() {
	int n = 0, arr[50001] = { 0 };
	scanf("%d", &n);
	for (int t = 1; t < 224; t++) arr[t * t] = 1;
	if (arr[n] == 1) {
		printf("1");
		return 0;
	}
	for (int t = 1;t < 224; t++) {
		for (int tt = t; tt * tt + t * t <= n; tt++) {
			arr[tt * tt + t * t] = 1;
		}
	}
	if (arr[n] == 1) {
		printf("2");
		return 0;
	}
	for (int t = 1; t * t <= n; t++) {
		if (arr[n - t * t] == 1) {
			printf("3");
			return 0;
		}
	}
	printf("4");
	return 0;
}