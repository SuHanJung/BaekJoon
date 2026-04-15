#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0, M = 0, B = 0, map[500][500] = { 0 }, totalBlock = 0, ansHeight = 0, ansTime = 0, ansCase[2] = { 1000000000, 100 };
	scanf("%d %d %d", &N, &M, &B);
	totalBlock = B;
	for (int height = 0; height < N; height++) {
		for (int width = 0; width < M; width++) {
			scanf("%d", &map[height][width]);
			totalBlock += map[height][width];
		}
	}
	for (ansHeight = totalBlock / (M * N); ansHeight >= 0; ansHeight--) {
		ansTime = 0;
		for (int height = 0; height < N; height++) {
			for (int width = 0; width < M; width++) {
				if (map[height][width] >= ansHeight) ansTime += (map[height][width] - ansHeight) * 2;
				else ansTime += (ansHeight - map[height][width]);
			}
		}
		if (ansTime < ansCase[0]) {
			ansCase[0] = ansTime;
			ansCase[1] = ansHeight;
		}
	}
	printf("%d %d", ansCase[0], ansCase[1]);
	return 0;
}