#include <stdio.h>
#include <stdlib.h>
int main() {
	int arrn = 0, qs[1000000] = {0}, qsn[1000000] = {0}, r = 0, arr[1000000] = {0};
	scanf("%d", &arrn);
	arr[0] = 0;
	for (int t = 0; t < arrn; t++)scanf("%d", &qs[t]);
	for (int t = 0; t < arrn; t++)scanf("%d", &qsn[t]);
	for (int t = arrn - 1; t >= 0; t--) {
		if (qs[t] == 0) {
			arr[0]++;
			arr[arr[0]] = qsn[t];
		}
	}
	scanf("%d", &r);
	for (int t = 0, inst = 0; t < r; t++) {
		scanf("%d", &inst);
		arr[0]++;
		arr[arr[0]] = inst;
	}
	for (int t = 1; t <= r; t++) {
		printf("%d ", arr[t]);
	}
	return 0;
}