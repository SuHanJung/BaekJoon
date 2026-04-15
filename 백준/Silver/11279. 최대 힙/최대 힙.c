#include <stdio.h>
#include <stdlib.h>
int main(){
	int arr[100001] = { 0 }, n = 0, input = 0, re = 0, k = 0;
	scanf("%d", &re);
	for (int t = 0; t < re; t++) {
		scanf("%d", &input);
		if (input == 0) {
			if (n == 0) printf("0\n");
			else {
				printf("%d\n", arr[1]);
				arr[1] = arr[n];
				arr[n] = 0;
				n--;
				for (int now = 1; now * 2 + 1 <= n;) {
					if (arr[now * 2] > arr[now * 2 + 1]) {
						if (arr[now * 2] > arr[now]) {
							k = arr[now];
							arr[now] = arr[now * 2];
							arr[now * 2] = k;
							now *= 2;
						}
						else break;
					}
					else {
						if (arr[now * 2 + 1] > arr[now]) {
							k = arr[now];
							arr[now] = arr[now * 2 + 1];
							arr[now * 2 + 1] = k;
							now = now * 2 + 1;
						}
						else break;
					}
				}
				if (arr[n] > arr[n / 2] && n > 1) {
					k = arr[n];
					arr[n] = arr[n / 2];
					arr[n / 2] = k;
				}
			}
		}
		else {
			n++;
			arr[n] = input;
			for (int now = n; now > 1; now /= 2) {
				if (arr[now] > arr[now / 2]) {
					k = arr[now];
					arr[now] = arr[now / 2];
					arr[now / 2] = k;
				}
				else break;
			}
		}
	}
	return 0;
}