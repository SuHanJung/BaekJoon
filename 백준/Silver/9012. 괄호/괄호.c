#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int input = 0, le = 0, ri = 0;
	char st[51] = { 0 };
	scanf("%d", &input);
	for (int time = 0; time < input; time++) {
		le = 0;
		ri = 0;
		scanf("%s", st);
		for (int t = 0;; t++) {
			if (st[t] == '(') le++;
			if (st[t] == ')') ri++;
			if (ri > le) {
				printf("NO\n");
				break;
			}
			if (st[t] == 0) {
				if (ri == le) {
					printf("YES\n");
					break;
				}
				else {
					printf("NO\n");
					break;
				}
			}
		}
		for (int t = 0; t < 50; t++) st[t] = 0;
	}
	return 0;
}