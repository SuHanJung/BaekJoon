#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char input[51][51] = { 0 };
	int size[2] = { 0 }, answer = 32, count = 0, sum[50][50] = { 0 };
	scanf("%d %d", &size[0], &size[1]);
	for (int t = 0; t < size[0]; t++) scanf("%s", input[t]);
	for (int t = 0; t <= size[0] * size[1]; t++) {
		if ((t % size[1]) % 2 == (t / size[1]) % 2) {
			if (input[t / size[1]][t % size[1]] == 'W') sum[t / size[1]][t % size[1]] = 1;
		}
		else {
			if (input[t / size[1]][t % size[1]] == 'B') sum[t / size[1]][t % size[1]] = 1;
		}
	}


	for (int k = 0; k < (size[0] - 7) * (size[1] - 7);k++) {
		count = 0;
		for (int t = 0; t < 64; t++) {
			count += sum[(k / (size[1] - 7)) + (t / 8)][(k % (size[1] - 7)) + (t % 8)];
		}
		if (count < answer) answer = count;
		if (64 - count < answer) answer = 64 - count;
	}
	printf("%d", answer);
	return 0;
}