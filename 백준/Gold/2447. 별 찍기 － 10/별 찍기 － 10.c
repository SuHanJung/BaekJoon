#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int sq[3][3] = { 0 }, input = 0, ch = 0;
	sq[1][1] = 1;
	scanf("%d", &input);
	for (int x = 0, y = 0, t = 0; t < input * input;t++) {
		for (int xx = x, yy = y, te = input;te > 1; xx /= 3, yy /= 3, te /= 3) {
			if (sq[xx % 3][yy % 3] == 1) {
				printf(" ");
				ch = 1;
				break;
			}
		}
		if (ch == 0) printf("*");
		ch = 0;
		if (x == input - 1) {
			x = 0;
			y++;
			printf("\n");
		}
		else x++;
	}
	return 0;
}