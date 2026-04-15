#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input[8] = { 0 };
	for (int time = 0; time < 8; time++) {
		scanf("%d", &input[time]);
	}
	for (int time = 0; time < 8; time++) {
		if (input[time] == time + 1) {
			if (time == 7) {
				printf("ascending");
				return 0;
			}
		}
		else break;
	}
	for (int time = 0; time < 8; time++) {
		if (input[time] == 8 - time) {
			if (time == 7) {
				printf("descending");
				return 0;
			}
		}
		else break;
	}
	printf("mixed");
	return 0;
}