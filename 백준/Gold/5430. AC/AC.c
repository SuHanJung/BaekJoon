#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int T = 0, n = 0, arr[100001] = { 0 }, start = 0, end = 0, ch = 0;
	char command[100001] = { 0 };
	scanf("%d", &T);
	for (int point = start; T > 0; T--) {
		while (getchar() != '\n');
		scanf("%s", command);
		while (getchar() != '\n');
		scanf("%d", &n);
		while (getchar() != '[');
		for (int t = 0; t < n; t++) {
			scanf("%d", &arr[t]);
			getchar();
		}
		start = 0;
		end = n - 1;
		point = start;
		for (int t = 0; command[t] != 0; t++) {
			if (command[t] == 'R') {
				if (point == start) point = end;
				else point = start;
			}
			else if (start > end) {
				ch = 1;
				break;
			}
			else if (point == start) {
				start++;
				point++;
			}
			else {
				point--;
				end--;
			}
		}
		if (start > end) {
			if (ch == 1) {
				printf("error\n");
				ch = 0;
			}
			else printf("[]\n");
		}
		else {
			if (point == start) {
				printf("[%d", arr[start]);
				for (int t = start + 1; t <= end; t++) printf(",%d", arr[t]);
				printf("]\n");
			}
			else if (point == end) {
				printf("[%d", arr[end]);
				for (int t = end - 1; t >= start; t--) printf(",%d", arr[t]);
				printf("]\n");
			}
		}
		for (int t = 0; t <= n; t++) arr[t] = 0;
		for (int t = 0; command[t] != 0; t++)command[t] = 0;
		n = 0;
	}
	return 0;
}