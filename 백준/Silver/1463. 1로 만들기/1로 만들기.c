#include <stdio.h>
int main() {
	int input = 0, k[3000001] = { 0 };
	scanf("%d", &input);
	if (input == 1) {
		printf("0");
		return 0;
	}
	for (int t = 1; t < input; t++) {
		if (k[t + 1] > k[t] + 1 || k[t + 1] == 0) k[t + 1] = k[t] + 1;
		if (k[t * 2] > k[t] + 1 || k[t * 2] == 0) k[t * 2] = k[t] + 1;
		if (k[t * 3] > k[t] + 1 || k[t * 3] == 0) k[t * 3] = k[t] + 1;
	}
	printf("%d ", k[input]);
	return 0;
}