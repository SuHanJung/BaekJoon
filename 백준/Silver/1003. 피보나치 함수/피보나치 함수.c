#include <stdio.h>

int main() {
	long long int arr[41] = { 0 };
	arr[1] = 1;
	for (int t = 2; t <= 40; t++)arr[t] = arr[t - 1] + arr[t - 2];
	int n = 0, p = 0;
	scanf("%d", &n);
	for (int t = 0; t < n; t++) {
		scanf("%d", &p);
		if (p == 0) printf("1 0\n");
		else {
			printf("%d %d\n", arr[p - 1], arr[p]);
		}
		p = 0;
	}
	return 0;
}