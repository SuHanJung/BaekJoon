#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input = 0;
	scanf("%d", &input);
	for (int time = 1; time <= input; time++) {
		printf("%d\n", time);
	}
	return 0;
}