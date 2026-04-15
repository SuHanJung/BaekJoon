#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int command = 0, n = 0, front[1000000] = { 0 }, back[1000000] = { 0 }, lf = 0, lb = 0;
	scanf("%d", &n);
	for (int time = 0; time < n; time++) {
		scanf("%d", &command);
		switch (command) {
		case 1:
			front[0]++;
			scanf("%d", &front[front[0]]);
			lf++;
			break;
		case 2:
			back[0]++;
			scanf("%d", &back[back[0]]);
			lb++;
			break;
		case 3:
			if (lf > 0) {
				printf("%d\n", front[front[0]]);
				front[front[0]] = 0;
				front[0]--;
				lf--;
				break;
			}
			else if (lb > 0) {
				lb--;
				printf("%d\n", back[back[0] - lb]);
				back[back[0] - lb] = 0;
				break;
			}
			else
				printf("-1\n");
			break;
		case 4:
			if (lb > 0) {
				printf("%d\n", back[back[0]]);
				back[back[0]] = 0;
				back[0]--;
				lb--;
				break;
			}
			else if (lf > 0) {
				lf--;
				printf("%d\n", front[front[0] - lf]);
				front[front[0] - lf] = 0;
				break;
			}
			else
				printf("-1\n");
			break;
		case 5:
			printf("%d\n", lf + lb);
			break;
		case 6:
			if (lf + lb == 0) printf("1\n");
			else printf("0\n");
			break;
		case 7:
			if (lf > 0) {
				printf("%d\n", front[front[0]]);
				break;
			}
			else if (lb > 0) {
				printf("%d\n", back[back[0] - lb + 1]);
				break;
			}
			else
				printf("-1\n");
			break;
		case 8:
			if (lb > 0) {
				printf("%d\n", back[back[0]]);
				break;
			}
			else if (lf > 0) {
				printf("%d\n", front[front[0] - lf + 1]);
				break;
			}
			else
				printf("-1\n");
			break;
		}
		command = 0;
	}
	return 0;
}