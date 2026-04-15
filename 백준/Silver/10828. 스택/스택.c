#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int J_stack(int st[]) {
	int len = st[0]; 
	char command[6] = { 0 };
	scanf("%s", command);
	switch (command[1])
	{
	case 'u':
		scanf("%d\n", &st[len + 1]);
		st[0]++;
		break;
	case 'o':
		if (command[0] == 't') {
			if (st[0] == 0) printf("-1\n");
			else printf("%d\n", st[len]);
			break;
		}
		else {
			if (len > 0) {
				printf("%d\n", st[len]);
				st[len] = 0;
				st[0]--;
			}
			else printf("-1\n");
			break;
		}
	case 'i':
		printf("%d\n", st[0]);
		break;
	case 'm':
		if (len == 0) printf("1\n");
		else printf("0\n");
		break;
	default:
		break;
	}
	return 0;
}

int main() {
	int Jstack[1000000] = { 0 }, input = 0;
	scanf("%d", &input);
	for (int time = 0; time < input; time++) {
		J_stack(Jstack);
	}
	return 0;
}