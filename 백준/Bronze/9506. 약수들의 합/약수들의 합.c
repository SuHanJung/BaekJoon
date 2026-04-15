#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 0;
	for (;;) {
		scanf("%d", &a);
		
		if (a == -1) return 0;

		switch (a) {
		default:
			printf("%d is NOT perfect.", a);
			break;
		case 6:
			printf("6 = 1 + 2 + 3");
			break;
		case 28:
			printf("28 = 1 + 2 + 4 + 7 + 14");
			break;
		case 496:
			printf("496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248");
			break;
		case 8128:
			printf("8128 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064");
			break;
		}
		printf("\n");
	}

	return 0;
}