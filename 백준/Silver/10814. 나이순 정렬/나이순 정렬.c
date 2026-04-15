#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0, arr[201] = { 0 }, t = 0;
	char words[100001][102] = { 0 };
	scanf("%d", &n);
	for (int time = 0; time < n; time++) {
		scanf("%d %s", &t, &words[time][1]);
		words[time][0] = t - 100;
		arr[t]++;
	}
	for (int nn = 0; nn < 201; nn++) {
		if (arr[nn] != 0) {
			for (; arr[nn] > 0;) {
				for (int count = 0; count < n; count++) {
					if (words[count][0] + 100 == nn) {
						printf("%d ", words[count][0] + 100);
						printf("%s\n", &words[count][1]);
						arr[nn]--;
					}
				}
			}
		}
	}

	return 0;
}