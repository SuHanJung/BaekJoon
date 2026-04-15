#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num[2000000] = { 0 }, n = 0, start = 0, end = 0;
	char command[6] = { 0 };
	scanf("%d", &n);
	for (int time = 0, inst = 0; time < n; time++) {
		scanf("%s", command);
		switch (command[1]){
		case 'u':
			scanf("%d", &inst);
			end++;
			if (start == 0) start++;
			num[end] = inst;
			break;
		case 'o':
			if ((start == 0) || (end - start < 0)) printf("-1\n");
			else {
				printf("%d\n", num[start]);
				start++;
			}
			break;
		case 'i':
			printf("%d\n", end - start + 1);
			break;
		case 'm':
			if ((start == 0) || (end - start < 0)) printf("1\n");
			else printf("0\n");
			break;
		case 'r':
			if ((start == 0) || (end - start < 0)) printf("-1\n");
			else printf("%d\n", num[start]);
			break;
		case 'a':
			if ((start == 0) || (end - start < 0)) printf("-1\n");
			else printf("%d\n", num[end]);
			break;
		}
	inst = 0;
	for (int t = 0; t < 5; t++)command[t] = 0;
	}
	return 0;
}