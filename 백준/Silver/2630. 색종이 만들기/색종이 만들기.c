#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ans[2] = { 0 }, in[128][128] = { 0 };


int sq(int spotx, int spoty, int len) {
	int total = 0;
	for (int y = spoty; y < spoty + len; y++) {
		for (int x = spotx; x < spotx + len; x++) total += in[y][x];
	}
	if (total == 0) {
		ans[total]++;
		return total;
	}
	else if(total == len * len) {
		total = 1;
		ans[total]++;
		return total;
	}
	else total = -1;
	int l = len / 2;
	sq(spotx, spoty, l);
	sq(spotx + l, spoty, l);
	sq(spotx, spoty + l, l);
	sq(spotx + l, spoty + l, l);
	return total;
}

int main() {
	int N = 0;
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) scanf("%d", &in[y][x]);
	}
	sq(0, 0, N);
	printf("%d\n%d", ans[0], ans[1]);
	return 0;
}